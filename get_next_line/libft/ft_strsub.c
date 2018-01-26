/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:40:04 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/08 16:40:06 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	string = (char *)malloc(len + 1);
	if (string == NULL)
		return (NULL);
	len = start + len;
	while (start < len && s[start] != '\0')
	{
		string[i] = s[start];
		i++;
		start++;
	}
	string[i] = '\0';
	return (string);
}
