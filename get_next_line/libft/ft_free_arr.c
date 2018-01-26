/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:26:24 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/15 18:26:27 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arr(char ***str_arr)
{
	size_t i;

	i = 0;
	if (str_arr != NULL)
	{
		while (*(*str_arr + i) != 0)
		{
			free(*(*str_arr + i));
			i++;
		}
		free(*str_arr);
		*str_arr = NULL;
	}
}
