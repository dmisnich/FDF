/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:14:31 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/09 11:14:34 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**string;

	i = -1;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(string = (char**)malloc(sizeof(char*) * (ft_word_len(s, c) + 1))))
		return (NULL);
	while (++i < ft_word_len(s, c))
	{
		while (s[j] == c)
			j++;
		if (!(*(string + i) = ft_strsub(s, j, ft_char_len(s, j, c))))
		{
			ft_free_arr(&string);
			return (NULL);
		}
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	string[ft_word_len(s, c)] = NULL;
	return (string);
}
