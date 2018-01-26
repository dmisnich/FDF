/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:30:02 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/03 12:30:03 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t i;

	i = 0;
	if (size == 0)
		return (0);
	while ((i != (size - 1))
		&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& ((unsigned char *)s1)[i] != '\0'
		&& ((unsigned char *)s2)[i] != '\0')
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
