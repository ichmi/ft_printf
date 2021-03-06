/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:28:36 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/21 11:29:12 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	char	*pb;

	if (!s)
		return (NULL);
	buff = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!buff)
		return (NULL);
	pb = buff;
	while (*s)
		*buff++ = *(char *)s++;
	return (pb);
}
