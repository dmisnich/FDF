/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:36:43 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/05 11:36:45 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *n, size_t len)
{
	if (*n == '\0')
		return ((char *)s);
	while ((*s != '\0') && (len-- >= ft_strlen(n)))
	{
		if (ft_strnequ(s, n, ft_strlen(n)) == 1)
			return ((char *)s);
		s++;
	}
	return (0);
}
