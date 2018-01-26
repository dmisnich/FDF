/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:13:23 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/03 14:13:25 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_whitespace(char c)
{
	return (c == '\n' || c == '\t' || c == '\r'
		|| c == ' ' || c == '\v' || c == '\f');
}

int				ft_atoi(const char *str)
{
	unsigned int		i;
	unsigned long int	result;
	int					minus;

	minus = 1;
	i = 0;
	result = 0;
	while (ft_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 7)) && minus == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
		&& (str[i] - '0') > 8)) && minus == -1)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * minus);
}
