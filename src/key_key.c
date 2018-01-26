/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:41:18 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 14:12:53 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 13 && mlx->key.s == 0)
		mlx->key.w = 1;
	if (keycode == 1 && mlx->key.w == 0)
		mlx->key.s = 1;
	if (keycode == 2 && mlx->key.d == 0)
		mlx->key.a = 1;
	if (keycode == 0 && mlx->key.a == 0)
		mlx->key.d = 1;
	if (keycode == 14 && mlx->key.e == 0)
		mlx->key.q = 1;
	if (keycode == 12 && mlx->key.q == 0)
		mlx->key.e = 1;
	if (keycode == 24)
		mlx->key.plus = 1;
	if (keycode == 27)
		mlx->key.minus = 1;
	if (keycode == 53)
		exit_x();
	if (keycode == 8)
		change_color(mlx);
	kp_2(keycode, mlx);
	return (0);
}

int		key_release(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
		mlx->key.w = 0;
	if (keycode == 1)
		mlx->key.s = 0;
	if (keycode == 2)
		mlx->key.a = 0;
	if (keycode == 0)
		mlx->key.d = 0;
	if (keycode == 14)
		mlx->key.q = 0;
	if (keycode == 12)
		mlx->key.e = 0;
	if (keycode == 24)
		mlx->key.plus = 0;
	if (keycode == 27)
		mlx->key.minus = 0;
	kr_2(keycode, mlx);
	return (0);
}

int		kb_1(t_mlx *mlx)
{
	if (mlx->key.w == 1)
	{
		rotate_x(mlx, -0.03);
		render(mlx);
	}
	if (mlx->key.s == 1)
	{
		rotate_x(mlx, 0.03);
		render(mlx);
	}
	if (mlx->key.q == 1)
	{
		rotate_z(mlx, -0.03);
		render(mlx);
	}
	if (mlx->key.plus == 1)
	{
		zoom(mlx, 1.035);
		render(mlx);
	}
	return (0);
}

int		kb_2(t_mlx *mlx)
{
	if (mlx->key.a == 1)
	{
		rotate_y(mlx, 0.03);
		render(mlx);
	}
	if (mlx->key.d == 1)
	{
		rotate_y(mlx, -0.03);
		render(mlx);
	}
	if (mlx->key.e == 1)
	{
		rotate_z(mlx, 0.03);
		render(mlx);
	}
	if (mlx->key.minus == 1)
	{
		zoom(mlx, 0.975);
		render(mlx);
	}
	return (0);
}

int		kb_move(t_mlx *mlx)
{
	if (mlx->key.up == 1)
	{
		move_y(mlx, -5);
		render(mlx);
	}
	if (mlx->key.down == 1)
	{
		move_y(mlx, 5);
		render(mlx);
	}
	if (mlx->key.left == 1)
	{
		move_x(mlx, 5);
		render(mlx);
	}
	if (mlx->key.right == 1)
	{
		move_x(mlx, -5);
		render(mlx);
	}
	return (0);
}
