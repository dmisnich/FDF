/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:08:04 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/08 14:08:05 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	int			j;
	int			k;
	int			size;
	char		*string;

	if (s == NULL)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	k = 0;
	while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
		j++;
	while (s[i - 1] == '\n' || s[i - 1] == '\t' || s[i - 1] == ' ')
		i--;
	if (i <= 0)
		size = j;
	else
		size = i - j;
	string = ft_strnew(size);
	if (string == NULL)
		return (NULL);
	while (k != size)
		string[k++] = s[j++];
	return (string);
}
