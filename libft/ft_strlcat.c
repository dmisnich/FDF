/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:48:36 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/01 18:48:37 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		res;

	if (size == 0)
		return (size + ft_strlen(src));
	res = ft_strlen(dst) + ft_strlen(src);
	if (res == 0)
		return (0);
	j = ft_strlen(dst);
	i = 0;
	if (size < j)
		return (size + ft_strlen(src));
	while (j < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (res);
}
