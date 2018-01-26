/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:43:23 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/08 16:43:25 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	size_t		i;
	char		*string;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	string = ft_strnew(size);
	if (string == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		string[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		string[i] = *s2;
		i++;
		s2++;
	}
	return (string);
}
