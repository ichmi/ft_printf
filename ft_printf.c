/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:04 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/23 22:32:54 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_check_spec(char spec, va_list ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (spec == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	if (spec == 'x' || spec == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), spec));
	if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

static int	__dotwidth_spec(char spec, char *buff, va_list ap)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'c')
	{
		if (ft_strlen(buff) > 1)
		{
			temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
			ft_memcpy(temp, buff, ft_strlen(buff));
			temp[ft_strlen(temp) - 1] = va_arg(ap, int);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putchar(va_arg(ap, int)));
	}
	if (spec == 'p')
	{
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s) - 2;
			temp = ft_calloc(ft_strlen(s) + delta + 3, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, "0x", -1);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr("0x");
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (s[0] == '-' && ft_strlen(buff) > ft_strlen(s) - 1)
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 2, sizeof(char));
			temp[0] = '-';
			ft_strlcat(temp, buff, ft_strlen(temp) + delta + 2);
			ft_strlcat(temp, s + 1, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		else if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'u')
	{
		s = ft_utoa(va_arg(ap, unsigned int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'x' || spec == 'X')
	{
		if (spec == 'x')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	return (0);
}

static int	__width_spec(char spec, char *buff, va_list ap)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'c')
	{
		if (ft_strlen(buff) > 1)
		{
			temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
			ft_memcpy(temp, buff, ft_strlen(buff));
			temp[ft_strlen(temp) - 1] = va_arg(ap, int);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putchar(va_arg(ap, int)));
	}
	if (spec == 's')
	{
		s = va_arg(ap, char *);
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putstr(s));
	}
	if (spec == 'p')
	{
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s) - 2;
			temp = ft_calloc(ft_strlen(s) + delta + 3, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, "0x", -1);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr("0x");
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			if (s[0] == '-')
			{
				temp[0] = '-';
				ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
				ft_strlcat(temp, s + 1, -1);
			}
			else
			{
				ft_memcpy(temp, buff, delta);
				ft_strlcat(temp, s, -1);
			}
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'u')
	{
		s = ft_utoa(va_arg(ap, unsigned int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'x' || spec == 'X')
	{
		if (spec == 'x')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	return (0);
}

static int	__single_spc(va_list ap)
{
	int		bw;
	char	*s;

	bw = 0;
	s = ft_itoa(va_arg(ap, int));
	if (s[0] == '-')
		bw += ft_putstr(s);
	else
	{
		bw += write(1, " ", 1);
		bw += ft_putstr(s);
	}
	free(s);
	return (bw);
}

static int	__minus_f(char spec, char *buff, va_list ap)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;
	int		c;

	bw = 0;
	if (spec == 'c')
	{
		if (ft_strlen(buff) > 1)
		{
			c = va_arg(ap, int);
			if (!c)
			{
				bw += write(1, "", 1);
				temp = ft_calloc(ft_strlen(buff), sizeof(char));
				ft_memcpy(temp, buff, ft_strlen(buff) - 1);
				bw += ft_putstr(temp);
			}
			else
			{
				temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
				ft_memcpy(temp, buff, ft_strlen(buff) + 1);
				temp[0] = c;
				bw += ft_putstr(temp);
			}
			free(temp);
			return (bw);
		}
		return (ft_putchar(va_arg(ap, int)));
	}
	if (spec == 's')
	{
		s = va_arg(ap, char *);
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, s, ft_strlen(s) + 1);
			ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putstr(s));
	}
	if (spec == 'p')
	{
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
		if (*s == '0')
		{
			if (ft_strlen(buff) > 5)
			{
				bw += ft_putstr("(nil)");
				temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
				ft_memcpy(temp, buff, ft_strlen(buff) - 5);
				bw += ft_putstr(temp);
				free(temp);
				free(s);
				return (bw);
			}
			free(s);
			return (write(1, "(nil)", 5));
		}
		else if (ft_strlen(buff) > ft_strlen(s) + 2)
		{
			delta = ft_strlen(buff) - ft_strlen(s); // 1
			temp = ft_calloc(2 + ft_strlen(s) + delta + 1, sizeof(char)); // 2 + 1 + 1 + 1 = 5 (4 + 1) -> 0x1\0
			ft_memcpy(temp, "0x", 3);
			ft_strlcat(temp, s, ft_strlen(temp) + ft_strlen(s) + 1);
			ft_strlcat(temp, buff, ft_strlen(temp) + (delta - 2) + 1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr("0x");
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, s, ft_strlen(s) + 1);
			ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'u')
	{
		s = ft_utoa(va_arg(ap, unsigned int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, s, ft_strlen(s) + 1);
			ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'x' || spec == 'X')
	{
		if (spec == 'x')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, s, ft_strlen(s) + 1);
			ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	return (0);
}

static int	__has_minus(const char **fmt, va_list ap)
{
	char	*buff;
	int		bw;
	int		n;

	++(*fmt);
	bw = 0;
	if (ft_isdigit(**fmt))
	{
		n = ft_atoi(*fmt);
		buff = ft_calloc(n + 1, sizeof(char));
		if (!buff)
			return (0);
		ft_memset(buff, ' ', n);
		while (!ft_strchr("cspdiuxX", **fmt))
			++(*fmt);
		if (ft_strchr("cspdiuxX", **fmt))
			bw += __minus_f(**fmt, buff, ap);
		free(buff);
		return (bw);
	}
	while (!ft_strchr("cspdiuxX", **fmt))
		++(*fmt);
	if (ft_strchr("cspdiuxX", **fmt))
		bw += ft_check_spec(**fmt, ap);
	return (bw);
}

static int	__has_width(int n, const char **fmt, va_list ap)
{
	int		bw;
	char	*buff;

	bw = 0;
	buff = ft_calloc(n + 1, sizeof(char));
	if (!buff)
		return (0);
	if (**fmt == '0')
		ft_memset(buff, '0', n);
	else
		ft_memset(buff, ' ', n);
	while (!ft_strchr("cspdiuxX", **fmt))
		++(*fmt);
	if (ft_strchr("cspdiuxX", **fmt))
		bw += __width_spec(**fmt, buff, ap);
	free(buff);
	return (bw);
}

static int	__spcwidth_spec(char spec, char *buff, va_list ap)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'c')
	{
		if (ft_strlen(buff) > 1)
		{
			temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
			ft_memcpy(temp, buff, ft_strlen(buff));
			temp[ft_strlen(temp) - 1] = va_arg(ap, int);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putchar(va_arg(ap, int)));
	}
	if (spec == 's')
	{
		s = va_arg(ap, char *);
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			return (bw);
		}
		return (ft_putstr(s));
	}
	if (spec == 'p')
	{
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s) - 2;
			temp = ft_calloc(ft_strlen(s) + delta + 3, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, "0x", -1);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr("0x");
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		if (s[0] == '-')
			bw += ft_putstr(s);
		else
		{
			bw += write(1, " ", 1);
			bw += ft_putstr(s);
		}
		free(s);
		return (bw);
	}
	if (spec == 'u')
	{
		s = ft_utoa(va_arg(ap, unsigned int));
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	if (spec == 'x' || spec == 'X')
	{
		if (spec == 'x')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
		if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	return (0);
}

static int	__has_spcwidth(int n, const char **fmt, va_list ap)
{
	int		bw;
	char	*buff;

	bw = 0;
	buff = ft_calloc(n + 1, sizeof(char));
	if (!buff)
		return (0);
	ft_memset(buff, ' ', n);
	while (!ft_strchr("cspdiuxX", **fmt))
		++(*fmt);
	if (ft_strchr("cspdiuxX", **fmt))
		bw += __spcwidth_spec(**fmt, buff, ap);
	free(buff);
	return (bw);
}

static int	__has_space(const char **fmt, va_list ap)
{
	int		bw;

	++(*fmt);
	if (**fmt == 's')
		return (ft_check_spec('s', ap));
	if (ft_isdigit(**fmt))
		bw = __has_spcwidth(ft_atoi(*fmt), fmt, ap);
	else
		bw = __single_spc(ap);
	while (!ft_strchr("cspdiuxX%", **fmt))
		++(*fmt);
	return (bw);
}

static int	__has_dotwidth(int n, char spec, va_list ap)
{
	int		bw;
	char	*buff;

	bw = 0;
	buff = ft_calloc(n + 1, sizeof(char));
	if (!buff)
		return (0);
	ft_memset(buff, '0', n);
	if (ft_strchr("cspdiuxX", spec))
		bw += __dotwidth_spec(spec, buff, ap);
	free(buff);
	return (bw);
}

static	int	__has_dot(const char **fmt, va_list ap)
{
	char	*s;
	int		bw;
	int		n;

	bw = 0;
	++(*fmt);
	if (ft_isdigit(**fmt))
	{
		n = ft_atoi(*fmt);
		while (!ft_strchr("cspdiuxX%", **fmt))
			(*fmt)++;
		if (**fmt == 's')
		{
			s = va_arg(ap, char *);
			if (n > (int)ft_strlen(s))
				bw += ft_putstr(s);
			else
				while (n--)
					bw += ft_putchar(*s++);
		}
		else
			bw += __has_dotwidth(n, **fmt, ap);
		return (bw);
	}
	s = va_arg(ap, char *);
	while (!ft_strchr("cspdiuxX%", **fmt))
		(*fmt)++;
	return (bw);
}

static int	__pluswidth_spec(char spec, char *buff, va_list ap, int zero)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (s[0] == '-' && ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			if (zero)
			{
				bw += write(1, "-", 1);
				ft_memcpy(temp, buff, delta);
				ft_strlcat(temp, s + 1, -1);
				bw += ft_putstr(temp);
				free(temp);
				free(s);
				return (bw);
			}
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		else if (ft_strlen(buff) > ft_strlen(s))
		{
			delta = ft_strlen(buff) - ft_strlen(s) - 1;
			temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
			if (zero)
			{
				bw += write(1, "+", 1);
				ft_memcpy(temp, buff, delta);
				ft_strlcat(temp, s, -1);
				bw += ft_putstr(temp);
				free(temp);
				free(s);
				return (bw);
			}
			ft_memcpy(temp, buff, delta);
			ft_strlcat(temp, "+", ft_strlen(temp) + 2);
			ft_strlcat(temp, s, -1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		if (s[0] == '-')
			bw += ft_putstr(s);
		else
		{
			bw += write(1, "+", 1);
			bw += ft_putstr(s);
		}
		free(s);
		return (bw);
	}
	return (0);
}

static int	__has_pluswidth(int n, const char **fmt, va_list ap, int zero)
{
	int		bw;
	char	*buff;

	bw = 0;
	buff = ft_calloc(n + 1, sizeof(char));
	if (!buff)
		return (0);
	if (zero)
		ft_memset(buff, '0', n);
	else
		ft_memset(buff, ' ', n);
	while (!ft_strchr("cspdiuxX", **fmt))
		++(*fmt);
	if (ft_strchr("cspdiuxX", **fmt))
		bw += __pluswidth_spec(**fmt, buff, ap, zero);
	free(buff);
	return (bw);
}

static int	__plus(const char **fmt, va_list ap)
{
	int		zero;
	int		bw;
	int		n;

	++(*fmt);
	bw = 0;
	if (ft_isdigit(**fmt))
	{
		zero = 0;
		if (**fmt == '0')
			zero = 1;
		n = ft_atoi(*fmt);
		while (!ft_strchr("cspdiuxX%", **fmt))
			(*fmt)++;
		bw += __has_pluswidth(n, fmt, ap, zero);
		return (bw);
	}
	n = va_arg(ap, int);
	if (n >= 0)
	{
		bw += write(1, "+", 1);
		bw += ft_putnbr(n);
	}
	else
		bw += ft_putnbr(n);
	return (bw);
}

static int	__sharpwidth(char spec, char *buff, va_list ap)
{
	size_t	delta;
	char	*temp;
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'x' || spec == 'X')
	{
		if (spec == 'x')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
		if (s[0] == '0')
		{
			bw += ft_putstr("0");
			free(s);
			return (bw);
		}
		if (ft_strlen(buff) > ft_strlen(s) + 2)
		{
			delta = ft_strlen(buff) - ft_strlen(s);
			temp = ft_calloc(2 + ft_strlen(s) + delta + 1, sizeof(char));
			ft_memcpy(temp, buff, delta - 2);
			if (spec == 'x')
				ft_strlcat(temp, "0x", ft_strlen(temp) + 3);
			else
				ft_strlcat(temp, "0X", ft_strlen(temp) + 3);
			ft_strlcat(temp, s, ft_strlen(temp) + ft_strlen(s) + 1);
			bw += ft_putstr(temp);
			free(temp);
			free(s);
			return (bw);
		}
		if (spec == 'x')
			bw += write(1, "0x", 2);
		else
			bw += write(1, "0X", 2);
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	return (0);
}

static int	__sharp(const char **fmt, va_list ap)
{
	int		n;
	int		bw;
	char	*buff;

	bw = 0;
	++(*fmt);
	if (ft_isdigit(**fmt))
	{
		n = ft_atoi(*fmt);
		buff = ft_calloc(n + 1, sizeof(char));
		if (!buff)
			return (0);
		ft_memset(buff, ' ', n);
		while (!ft_strchr("cspdiuxX", **fmt))
			++(*fmt);
		if (ft_strchr("xX", **fmt))
			bw += __sharpwidth(**fmt, buff, ap);
		free(buff);
		return (bw);
	}
	buff = ft_strdup("");
	bw += __sharpwidth(**fmt, buff, ap);
	free(buff);
	return (bw);
}

int	ft_printf(const char *fmt, ...)
{
	int		bw;
	va_list	ap;

	va_start(ap, fmt);
	bw = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '#')
				bw += __sharp(&fmt, ap);
			else if (*fmt == '+')
				bw += __plus(&fmt, ap);
			else if (*fmt == '-')
				bw += __has_minus(&fmt, ap);
			else if (*fmt == '.')
				bw += __has_dot(&fmt, ap);
			else if (*fmt == ' ')
				bw += __has_space(&fmt, ap);
			else if (ft_isdigit(*fmt))
				bw += __has_width(ft_atoi(fmt), &fmt, ap);
			else if (ft_strchr("cspdiuxX%", *fmt))
				bw += ft_check_spec(*fmt, ap);
		}
		else
			bw += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (bw);
}
