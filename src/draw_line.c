/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:36:21 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:32:16 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_mlx *mlx, float value)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			mlx->coord[y][x].x = mlx->coord[y][x].x * value;
			mlx->coord[y][x].y = mlx->coord[y][x].y * value;
			mlx->coord[y][x].z = mlx->coord[y][x].z * value;
			x++;
		}
		y++;
	}
}

void	write_in_display(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx, mlx->win, 50, 55, 0xFFFFFF, "---- CONTROL ----");
	mlx_string_put(mlx->mlx, mlx->win, 50, 70, 0xFFFFFF, "| Up:      'W'  |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 90, 0xFFFFFF, "| Down:    'S'  |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 110, 0xFFFFFF, "| Left:    'A   |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 130, 0xFFFFFF, "| Right:   'D'  |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 150, 0xFFFFFF, "| Left_z:  'Q'  |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 170, 0xFFFFFF, "| Right_z: 'E'  |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 185, 0xFFFFFF, "-----------------");
	mlx_string_put(mlx->mlx, mlx->win, 50, 200, 0xFFFFFF, "-- TRANSLATION --");
	mlx_string_put(mlx->mlx, mlx->win, 50, 220, 0xFFFFFF, "| Up:    'UP'   |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 240, 0xFFFFFF, "| Down:  'DOWN' |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 260, 0xFFFFFF, "| Left:  'LEFT' |");
	mlx_string_put(mlx->mlx, mlx->win, 50, 280, 0xFFFFFF, "| Right: 'RIGHT'|");
	mlx_string_put(mlx->mlx, mlx->win, 50, 300, 0xFFFFFF, "-----------------");
	mlx_string_put(mlx->mlx, mlx->win, 1750, 55, 0xFFFFFF, "----- ZOOM ----");
	mlx_string_put(mlx->mlx, mlx->win, 1750, 70, 0xFFFFFF, "| Plus:  '+'  |");
	mlx_string_put(mlx->mlx, mlx->win, 1750, 90, 0xFFFFFF, "| Minus: '-'  |");
	mlx_string_put(mlx->mlx, mlx->win, 1750, 105, 0xFFFFFF, "---------------");
	mlx_string_put(mlx->mlx, mlx->win, 1750, 125, 0xFFFFFF, "| Color: 'C'  |");
}

t_line	new_line(t_vector point0, t_vector point1)
{
	t_line	line;

	line.x0 = point0.x + (WIN_WIDTH / 2);
	line.y0 = point0.y + (WIN_HEIGHT / 2);
	line.x1 = point1.x + (WIN_WIDTH / 2);
	line.y1 = point1.y + (WIN_HEIGHT / 2);
	line.dx = abs(line.x1 - line.x0);
	line.dy = abs(line.y1 - line.y0);
	line.sx = line.x0 < line.x1 ? 1 : -1;
	line.sy = line.y0 < line.y1 ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -(line.dy)) / 2;
	line.e2 = 0;
	return (line);
}

void	render(t_mlx *mlx)
{
	int		x;
	int		y;

	y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	write_in_display(mlx);
	while (y < mlx->max.max_y)
	{
		x = 0;
		while (x < mlx->max.max_x)
		{
			if (x + 1 < mlx->max.max_x)
				draw_line(mlx, new_line(mlx->coord[y][x],
					mlx->coord[y][x + 1]));
			if (y + 1 < mlx->max.max_y)
				draw_line(mlx, new_line(mlx->coord[y][x],
					mlx->coord[y + 1][x]));
			x++;
		}
		y++;
	}
}

void	draw_line(t_mlx *mlx, t_line line)
{
	while (1)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, line.x0, line.y0, mlx->key.color);
		if (line.x0 == line.x1 && line.y0 == line.y1)
			break ;
		line.e2 = line.err;
		if (line.e2 > -line.dx)
		{
			line.err -= line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}
