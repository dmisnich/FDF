/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:44:06 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:14:53 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_mlx *mlx, float value)
{
	int		x;
	int		y;
	float	dy;
	float	dz;
	double	radian;

	x = 0;
	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			dy = mlx->coord[y][x].y;
			dz = mlx->coord[y][x].z;
			radian = atan2(dy, dz) + value;
			mlx->coord[y][x].y = hypot(dy, dz) * sin(radian);
			mlx->coord[y][x].z = hypot(dy, dz) * cos(radian);
			x++;
		}
		y++;
	}
}

void	rotate_y(t_mlx *mlx, float value)
{
	int		x;
	int		y;
	float	dx;
	float	dz;
	double	radian;

	x = 0;
	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			dx = mlx->coord[y][x].x;
			dz = mlx->coord[y][x].z;
			radian = atan2(dx, dz) + value;
			mlx->coord[y][x].x = hypot(dx, dz) * sin(radian);
			mlx->coord[y][x].z = hypot(dx, dz) * cos(radian);
			x++;
		}
		y++;
	}
}

void	rotate_z(t_mlx *mlx, float value)
{
	int		x;
	int		y;
	float	dx;
	float	dy;
	double	radian;

	x = 0;
	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			dx = mlx->coord[y][x].x;
			dy = mlx->coord[y][x].y;
			radian = atan2(dx, dy) + value;
			mlx->coord[y][x].x = hypot(dx, dy) * sin(radian);
			mlx->coord[y][x].y = hypot(dx, dy) * cos(radian);
			x++;
		}
		y++;
	}
}
