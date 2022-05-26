/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:08:06 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/21 11:22:56 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	char	*pb;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	buff = (char *)malloc(size + 1);
	if (!buff)
		return (NULL);
	pb = buff;
	ft_strlcpy(buff, s1, -1);
	ft_strlcat(buff, s2, -1);
	return (pb);
}
