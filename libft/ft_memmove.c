/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:18:52 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/04 13:18:55 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t size)
{
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dest > src)
	{
		while (size--)
			*((unsigned char*)dest + size) = *((unsigned char*)src + size);
	}
	else
		dest = ft_memcpy(dest, src, size);
	return (dest);
}
