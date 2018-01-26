/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:26:01 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:35:39 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_join_file(t_mlx *mlx, int fd)
{
	char	*tmp;
	char	*line;
	char	*content;
	int		max;

	max = 0;
	content = ft_strdup("");
	while (get_next_line(fd, &line))
	{
		mlx->max.max_x = ft_word_len(line, ' ');
		if (max == 0)
			max = mlx->max.max_x;
		if (max != mlx->max.max_x)
			error();
		tmp = content;
		content = ft_strjoin(content, line);
		free(line);
		free(tmp);
		tmp = content;
		content = ft_strjoin(content, "\n");
		free(tmp);
		mlx->max.max_y++;
	}
	write_down_arr(content, mlx);
}

void		write_down_arr(char *content, t_mlx *mlx)
{
	int		x;
	int		y;
	char	**grid;
	char	**tmp_grid;

	y = 0;
	mlx->coord = (t_vector **)malloc(sizeof(t_vector *) * mlx->max.max_y);
	grid = ft_strsplit(content, '\n');
	while (y < mlx->max.max_y)
	{
		tmp_grid = ft_strsplit(grid[y], ' ');
		mlx->coord[y] = (t_vector *)malloc(sizeof(t_vector) * mlx->max.max_x);
		x = 0;
		while (x < mlx->max.max_x)
		{
			mlx->coord[y][x].x = (float)x;
			mlx->coord[y][x].y = (float)y;
			mlx->coord[y][x].z = (float)ft_atoi(tmp_grid[x]);
			x++;
		}
		y++;
		ft_free_arr(&tmp_grid);
	}
	free(content);
	ft_free_arr(&grid);
}

void		multi_map(t_mlx *mlx, float value)
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
			mlx->coord[y][x].z = mlx->coord[y][x].z * HEIGHT_Z;
			x++;
		}
		y++;
	}
}
