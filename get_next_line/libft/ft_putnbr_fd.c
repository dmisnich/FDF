/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:05:20 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/13 12:05:21 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;
	char			res;

	i = 1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	while ((nb / i) > 9)
		i = i * 10;
	while (i > 0)
	{
		res = (nb / i) + '0';
		nb = nb % i;
		i = i / 10;
		write(fd, &res, 1);
	}
}
