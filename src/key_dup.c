/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:48:55 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 14:12:41 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	kp_2(int keycode, t_mlx *mlx)
{
	if (keycode == 126 && mlx->key.down == 0
		&& mlx->key.left == 0 && mlx->key.right == 0)
		mlx->key.up = 1;
	else if (keycode == 125 && mlx->key.up == 0
		&& mlx->key.left == 0 && mlx->key.right == 0)
		mlx->key.down = 1;
	else if (keycode == 124 && mlx->key.right == 0
		&& mlx->key.down == 0 && mlx->key.up == 0)
		mlx->key.left = 1;
	else if (keycode == 123 && mlx->key.left == 0
		&& mlx->key.up == 0 && mlx->key.down == 0)
		mlx->key.right = 1;
}

void	kr_2(int keycode, t_mlx *mlx)
{
	if (keycode == 126)
		mlx->key.up = 0;
	else if (keycode == 125)
		mlx->key.down = 0;
	else if (keycode == 124)
		mlx->key.left = 0;
	else if (keycode == 123)
		mlx->key.right = 0;
}
