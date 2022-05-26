/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_spec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 03:54:55 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/25 22:41:39 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	__zero_c(char *buff, va_list ap)
{
	char	*temp;
	int		bw;

	temp = ft_calloc(ft_strlen(buff) + 1, sizeof(char));
	ft_memcpy(temp, buff, ft_strlen(buff));
	temp[ft_strlen(temp) - 1] = va_arg(ap, int);
	bw = ft_putstr(temp);
	free(temp);
	return (bw);
}

int	__zero_s(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

	delta = ft_strlen(buff) - ft_strlen(s);
	temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
	if (!*s)
		ft_memcpy(temp, buff, ft_strlen(buff) + 1);
	else
	{
		ft_memcpy(temp, s, ft_strlen(s) + 1);
		ft_strlcat(temp, buff, ft_strlen(temp) + delta + 1);
	}
	bw = ft_putstr(temp);
	free(temp);
	return (bw);
}

int	__zero_p(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

	delta = ft_strlen(buff) - ft_strlen(s) - 2;
	temp = ft_calloc(ft_strlen(s) + delta + 3, sizeof(char));
	ft_memcpy(temp, buff, delta);
	ft_strlcat(temp, "0x", -1);
	ft_strlcat(temp, s, -1);
	bw = ft_putstr(temp);
	free(temp);
	free(s);
	return (bw);
}

int	__zero_id(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

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
	bw = ft_putstr(temp);
	free(temp);
	free(s);
	return (bw);
}

int	__zero_ux(char *buff, char *s)
{
	size_t	delta;
	char	*temp;
	int		bw;

	delta = ft_strlen(buff) - ft_strlen(s);
	temp = ft_calloc(ft_strlen(s) + delta + 1, sizeof(char));
	ft_memcpy(temp, buff, delta);
	ft_strlcat(temp, s, -1);
	bw = ft_putstr(temp);
	free(temp);
	free(s);
	return (bw);
}
