/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:59:04 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/18 17:15:29 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			if (ft_strchr("cspdiuxX%", *fmt))
				bw += ft_check_spec(*fmt, ap);
		}
		else
			bw += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (bw);
}
