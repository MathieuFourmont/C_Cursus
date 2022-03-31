/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:56:04 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/31 14:05:52 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_handler(int key, t_fdf *data)
{
	if (key == 53)
	{
		free_struct(data);
		exit (0);
	}
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		translation(key, data);
	else if (key == 69 || key == 24 || key == 27 || key == 78)
		zoom_map(key, data);
	else if (key == 34 || key == 35)
		set_projection(key, data);
	else if (key == 43 || key == 47)
		rotate_model(key, data);
	else if (key == 6 || key == 7)
		zoom_z(key, data);
	else if (key == 15)
		set_default(data);
	return (0);
}

void	print_commands(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 65, 20, 0x48D413, "COMMANDS MENU:");
	mlx_string_put(data->mlx, data->win, 65, 60, 0xFFC300, "Zoom: + / -");
	mlx_string_put(data->mlx, data->win,
		65, 80, 0xFFC300, "Zoom Z axis: z / x");
	mlx_string_put(data->mlx, data->win, 65, 100, 0xFFC300, "Move: arrows");
	mlx_string_put(data->mlx, data->win,
		65, 120, 0xFFC300, "Rotate: < / >");
	mlx_string_put(data->mlx, data->win,
		65, 140, 0xFFC300, "Set to default: R");
	mlx_string_put(data->mlx, data->win, 65, 180, 0x48D413, "PROJECTIONS:");
	mlx_string_put(data->mlx, data->win, 70, 220, 0xFFC300, "- Isometric: I");
	mlx_string_put(data->mlx, data->win, 70, 240, 0xFFC300, "- Parallel: P");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_lenght
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	init_data(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "FDF_BON / mmaxime-");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_lenght, &data->img.endian);
	data->zoom = 20;
	data->z_zoom = 1;
	data->shift_x = 825;
	data->shift_y = 325;
	data->rad = 0.523599;
	data->is_iso = true;
	draw_line_between_dots(data);
	print_commands(data);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
		ft_error("Error: usage: ./fdf map.fdf");
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		ft_error("Malloc error on data");
	read_map(argv[1], data);
	init_data(data);
	mlx_hook(data->win, 17, (1L << 17), &close_win, data);
	mlx_hook(data->win, 2, 0, key_handler, data);
	mlx_loop(data->mlx);
	return (0);
}
