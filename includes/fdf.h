/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:33:34 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 13:50:58 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080
# define HEIGHT_Z 10
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../miniLibX/mlx.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct	s_max
{
	int			max_x;
	int			max_y;
	float		mid_x;
	float		mid_y;
}				t_max;

typedef struct	s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			q;
	int			e;
	int			color;
	int			esc;
	int			up;
	int			down;
	int			left;
	int			right;
	int			plus;
	int			minus;
}				t_key;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_line;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
	int			color;

}				t_vector;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_vector	**coord;
	t_key		key;
	t_max		max;
}				t_mlx;

int				exit_x(void);
int				exit_esc(int keycode);
void			error(void);

/*
**	MAIN.C
*/

void			init_mlx(t_mlx *mlx);
int				keyboard(t_mlx *mlx);
int				middle_map(t_mlx *mlx, float value);
void			change_color(t_mlx *mlx);

/*
**	ROTATE.C
*/

void			rotate_x(t_mlx *mlx, float value);
void			rotate_y(t_mlx *mlx, float value);
void			rotate_z(t_mlx *mlx, float value);

/*
**	DRAW_LINE.C
*/

void			draw_line(t_mlx *mlx, t_line line);
void			render(t_mlx *mlx);
void			multi_map(t_mlx *mlx, float value);
void			zoom(t_mlx *mlx, float value);
void			write_in_display(t_mlx *mlx);
t_line			new_line(t_vector point0, t_vector point1);

/*
**	KEY_KEY.C
*/

int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
int				kb_1(t_mlx *mlx);
int				kb_2(t_mlx *mlx);
int				kb_move(t_mlx *mlx);

/*
** KEY_DUP.C
*/

void			kp_2(int keycode, t_mlx *mlx);
void			kr_2(int keycode, t_mlx *mlx);

/*
**	MOVE_FD.C
*/

void			move_x(t_mlx *mlx, float value);
void			move_y(t_mlx *mlx, float value);
void			move_points(t_mlx *mlx);

/*
**	FILE.C
*/

void			read_join_file(t_mlx *mlx, int fd);
void			write_down_arr(char *content, t_mlx *mlx);

#endif
