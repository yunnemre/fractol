/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:35:14 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/17 15:29:18 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	handle_pixel(int x, int y, t_fractal *data)
{
	t_complex	z;
	t_complex	j;
	int			i;
	int			idx;

	z.x = (map(x, data->range_x) * data->zoom) + data->shift_x;
	z.y = (map(y, data->range_y) * data->zoom) + data->shift_y;
	if (!ft_strncmp(data->name, "julia", 5))
		i = julia(z, data->iterations_def, data->julia_x, data->julia_y);
	else if (!ft_strncmp(data->name, "multijul", 9))
	{
		j.x = data->julia_x;
		j.y = data->julia_y;
		i = multi_jul(z, data->iterations_def, j, data->pow);
	}
	else if (!ft_strncmp(data->name, "multibrot", 10))
		i = multibrot(z, data->iterations_def, data->pow);
	else
		i = mandelbrot(z, data->iterations_def);
	idx = (int)((double)i / (double)data->iterations_def * (PALETE_SIZE - 1));
	if (i == data->iterations_def)
		my_pixel_put(x, y, &data->img, SILVER);
	else
		my_pixel_put(x, y, &data->img, data->palette[idx]);
}

void	render(t_fractal *data)
{
	int	x;
	int	y;

	ft_memset(data->img.pixels_ptr, 0, WIDHT * HEIGHT * 4);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDHT)
			handle_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	mlx_do_sync(data->mlx);
}

// eger ben  olceklendirme 4 ve 1 gibi rakamlarla yaparsam sekil 
	//bozulur her kısmı almaz yada herseyi alır fazla render
//hypot(z.x, z.y) cevircen sqrt kulanarak 2 ile karsılartırabilirdin 
//sayıalrn ormali ile ancak yine yavas kacar diyor