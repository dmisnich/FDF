/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 11:34:47 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/03 11:34:49 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (*((unsigned char *)s1) == '\0' && *((unsigned char *)s2) == '\0')
		return (0);
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]
		&& ((unsigned char *)s1)[i] != '\0' && ((unsigned char *)s2)[i] != '\0')
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
