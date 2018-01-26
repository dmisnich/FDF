/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:44:45 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/09 10:44:52 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_change(char *res, int i, int j, long int nb1)
{
	while (i > 0)
	{
		res[j++] = (nb1 / i) + '0';
		nb1 = nb1 % i;
		i = i / 10;
	}
	return (res);
}

char			*ft_itoa(int nb)
{
	unsigned int	i;
	int				j;
	int				size;
	char			*res;
	long int		nb1;

	i = 1;
	nb1 = (long int)nb;
	j = 0;
	size = 1;
	if (nb < 0)
	{
		nb1 = nb1 * -1;
		j = 1;
	}
	while ((nb1 / i) > 9 && size++)
		i = i * 10;
	res = ft_strnew(size + j);
	if (res == NULL)
		return (NULL);
	if (j)
		res[0] = '-';
	return (ft_change(res, i, j, nb1));
}
