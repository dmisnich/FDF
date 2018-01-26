/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:07:12 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/04 15:07:14 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < (len))
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
		{
			return ((unsigned char *)s + i);
		}
		i++;
	}
	return (NULL);
}
