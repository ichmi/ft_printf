/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:04 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/21 11:02:01 by frosa-ma         ###   ########.fr       */
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
			s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
		else if (spec == 'X')
			s = ft_ultoa(va_arg(ap, unsigned long), "0123456789ABCDEF");
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

int	__single_spc(va_list ap)
{
	int		n;
	int		bw;
	char	*s;

	bw = 0;
	n = va_arg(ap, int);
	if (n > 0)
	{
		s = ft_itoa(n);
		bw += write(1, " ", 1);
		bw += ft_putstr(s);
		free(s);
		return (bw);
	}
	bw += ft_putnbr(n);
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

static int	__has_space(const char **fmt, va_list ap)
{
	int		bw;

	++(*fmt);
	if (ft_isdigit(**fmt) && **fmt == '0')
		bw = __has_width(ft_atoi(*fmt), fmt, ap);
	else
		bw = __single_spc(ap);
	while (!ft_strchr("cspdiuxX%", **fmt))
		++(*fmt);
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
			// if (*fmt == '-')
				// fn(&fmt, f);
			if (*fmt == ' ')
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
