/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:08:15 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/29 16:24:05 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1080

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdbool.h>

/*
** ------------------------------ STRUCT DECLARATION ----------------------
*/

typedef	struct s_position
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}				t_position;

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef	struct s_fdf
{
	t_data	img;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		z_zoom;
	int		z_max;
	int		color;
	int		shift_x;
	int		shift_y;
	bool	is_iso;
	float	rad;
	void	*mlx;
	void	*win;
}				t_fdf;

/*
** ------------------------------ PROTOTYPES -----------------------------
*/

void	ft_error(char *str);
void	ft_free(char **ptr);
void	read_map(char *map_file, t_fdf *data);
void	bresenham(t_position dots_line, t_fdf *data);
void	isometric(float *x, float *y, int z, float rad);
int		who_is_max(float a, float b);
float	abs_value(float a);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line_between_dots(t_fdf *data);
int		close_win(t_fdf *vars);
void	free_ptr(char **ptr);
void	free_struct(t_fdf *data);
void	freetab(char **argv);
int		maplen(char **num);
int		is_number(char *str);
void	map_check(char **num);

#endif