/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_dispatcher_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:53:30 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/25 22:41:51 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	__zero_c(char *buff, va_list ap);
int	__zero_s(char *buff, char *s);
int	__zero_p(char *buff, char *s);
int	__zero_id(char *buff, char *s);
int	__zero_ux(char *buff, char *s);

static int	__spec_cs(char spec, char *buff, va_list ap)
{
	char	*s;

	if (spec == 'c')
	{
		if (ft_strlen(buff) > 1)
			return (__zero_c(buff, ap));
		return (ft_putchar(va_arg(ap, int)));
	}
	else if (spec == 's')
	{
		s = va_arg(ap, char *);
		if (ft_strlen(buff) > ft_strlen(s))
			return (__zero_s(buff, s));
		return (ft_putstr(s));
	}
	return (0);
}

static int	__spec_p(char *buff, va_list ap)
{
	char	*s;
	int		bw;

	bw = 0;
	s = __getstr('p', ap);
	if (ft_strlen(buff) > ft_strlen(s))
		return (__zero_p(buff, s));
	bw += ft_putstr("0x");
	bw += ft_putstr(s);
	free(s);
	return (bw);
}

static int	__spec_uid(char spec, char *buff, va_list ap)
{
	char	*s;
	int		bw;

	bw = 0;
	if (spec == 'd' || spec == 'i')
	{
		s = ft_itoa(va_arg(ap, int));
		if (ft_strlen(buff) > ft_strlen(s))
			return (__zero_id(buff, s));
		bw = ft_putstr(s);
	}
	else if (spec == 'u')
	{
		s = ft_utoa(va_arg(ap, unsigned int));
		if (ft_strlen(buff) > ft_strlen(s))
			return (__zero_ux(buff, s));
		bw = ft_putstr(s);
	}
	free(s);
	return (bw);
}

static int	__spec_hex(char spec, char *buff, va_list ap)
{
	char	*s;
	int		bw;

	s = __getstr(spec, ap);
	if (ft_strlen(buff) > ft_strlen(s))
		return (__zero_ux(buff, s));
	bw = ft_putstr(s);
	free(s);
	return (bw);
}

int	__zero_dispatch(char spec, char *buff, va_list ap)
{
	if (spec == 'c' || spec == 's')
		return (__spec_cs(spec, buff, ap));
	if (spec == 'p')
		return (__spec_p(buff, ap));
	if (spec == 'd' || spec == 'i' || spec == 'u')
		return (__spec_uid(spec, buff, ap));
	if (spec == 'x' || spec == 'X')
		return (__spec_hex(spec, buff, ap));
	return (0);
}
