/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:39:25 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:15:17 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	jul_pixel(int x, int y, t_fractal *jul)
{
	t_complex	z;
	int			i;

	z.x = (map(x, jul->range_x) * jul->zoom) + jul->shift_x;
	z.y = (map(y, jul->range_y) * jul->zoom) + jul->shift_y;
	i = julia(z, jul->iterations_def, jul->julia_x, jul->julia_y);
	if (i == jul->iterations_def)
		my_pixel_put(x, y, &jul->img, MAGENTA);
	else
		my_pixel_put(x, y, &jul->img, jul->palette[i % PALETE_SIZE]);
}

void	jul_render(t_fractal *jul)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDHT / 2)
			jul_pixel(x, y, jul);
	}
	mlx_put_image_to_window(jul->mlx, jul->win, jul->img.img_ptr, 0, 0);
}

static void	jul_init(t_fractal *jul, t_fractal *data)
{
	jul->name = "julia";
	jul->mlx = data->mlx;
	jul->win = mlx_new_window(jul->mlx, WIDHT / 2, HEIGHT / 2, "Julia");
	jul->img.img_ptr = mlx_new_image(jul->mlx, WIDHT / 2, HEIGHT / 2);
	jul->img.pixels_ptr = mlx_get_data_addr(jul->img.img_ptr, &jul->img.bpp,
			&jul->img.line, &jul->img.endian);
	jul->palette = data->palette;
	jul->range_x = data->range_x;
	jul->range_x.old_max = WIDHT / 2;
	jul->range_y = data->range_y;
	jul->range_y.old_max = HEIGHT / 2;
	jul->escape_val = data->escape_val;
	jul->iterations_def = data->iterations_def;
	jul->shift_x = data->shift_x * 0.5;
	jul->shift_y = data->shift_y * 0.5;
	jul->zoom = 1.0;
	jul->mutex_val = 0;
}

void	julia_win(int x, int y, t_fractal *data)
{
	t_fractal	*jul;

	jul = malloc(sizeof(t_fractal));
	if (!jul)
		return ;
	jul_init(jul, data);
	jul->julia_x = map(x, data->range_x) * data->zoom + data->shift_x;
	jul->julia_y = map(y, data->range_y) * data->zoom + data->shift_y;
	data->jul = jul;
	jul_render(jul);
	mlx_hook(jul->win, 17, 0, jul_close_sig, data);
	mlx_hook(jul->win, 4, 1L << 2, jul_mouse_sig, jul);
	mlx_key_hook(jul->win, jul_input_sig, jul);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	mlx_loop(jul->mlx);
}

int	julia_win_man(int x, int y, t_fractal *data)
{
	if (!data->jul)
		julia_win(x, y, data);
	else
	{
		data->jul->shift_x = 0;
		data->jul->shift_y = 0;
		data->jul->zoom = 1;
		data->jul->julia_x = map(x, data->range_x) * data->zoom + data->shift_x;
		data->jul->julia_y = map(y, data->range_y) * data->zoom + data->shift_y;
		//printf("x%f y%f\n",data->jul->julia_x,data->jul->julia_y);
		jul_render(data->jul);
	}
	draw_crosshair(&data->img, x, y, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}
