/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:39:46 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/27 19:07:28 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*__getstr(char spec, va_list ap)
{
	char	*s;

	if (spec == 'p')
		s = ft_ultoa(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (spec == 'x')
		s = ft_utoab(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		s = ft_utoab(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (s);
}
