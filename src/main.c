/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 11:33:46 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:21:10 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	mlx;
	int		fd;

	fd = 0;
	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	init_mlx(&mlx);
	read_join_file(&mlx, fd);
	multi_map(&mlx, 50);
	middle_map(&mlx, 50);
	move_points(&mlx);
	rotate_x(&mlx, -0.6);
	rotate_y(&mlx, -0.5);
	render(&mlx);
	mlx_hook(mlx.win, 2, 0, key_press, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_x, &mlx);
	mlx_loop_hook(mlx.mlx, keyboard, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

void	change_color(t_mlx *mlx)
{
	if (mlx->key.color >= 255)
	{
		mlx->key.color = mlx->key.color >> 8;
		render(mlx);
	}
	if (mlx->key.color < 255)
	{
		mlx->key.color = 0xFFFFFF;
		render(mlx);
	}
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx,
	WIN_WIDTH, WIN_HEIGHT, "FDF - dmisnich");
	mlx->max.max_y = 0;
	mlx->max.max_x = 0;
	mlx->key.w = 0;
	mlx->key.s = 0;
	mlx->key.a = 0;
	mlx->key.d = 0;
	mlx->key.q = 0;
	mlx->key.e = 0;
	mlx->key.plus = 0;
	mlx->key.minus = 0;
	mlx->key.color = 0xFFFFFF;
}

int		keyboard(t_mlx *mlx)
{
	kb_1(mlx);
	kb_2(mlx);
	kb_move(mlx);
	return (0);
}

int		middle_map(t_mlx *mlx, float value)
{
	mlx->max.mid_x = (mlx->max.max_x * value) / 2;
	mlx->max.mid_y = (mlx->max.max_y * value) / 2;
	return (0);
}
