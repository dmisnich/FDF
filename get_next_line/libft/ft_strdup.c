/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:30:51 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/01 12:30:53 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t		i;
	size_t		size_m;
	char		*string;

	i = 0;
	size_m = ft_strlen(str);
	string = (char*)malloc((size_m * sizeof(char)) + 1);
	if (string == NULL)
		return (NULL);
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
