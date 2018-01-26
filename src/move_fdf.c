/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:42:50 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:33:31 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(t_mlx *mlx, float value)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			mlx->coord[y][x].x = mlx->coord[y][x].x + value;
			x++;
		}
		y++;
	}
}

void	move_y(t_mlx *mlx, float value)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			mlx->coord[y][x].y = mlx->coord[y][x].y + value;
			x++;
		}
		y++;
	}
}

void	move_points(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			mlx->coord[y][x].x -= mlx->max.mid_x;
			mlx->coord[y][x].y -= mlx->max.mid_y;
			x++;
		}
		y++;
	}
}
