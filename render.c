/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:35:14 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/25 03:31:30 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;
	
	offset = (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

int rainbow_color(int i, int max_iter)
{
    double t = (double)i / max_iter; // 0.0 - 1.0 arası normalizasyon
    int r = (int)(9*(1-t)*t*t*t*255);
    int g = (int)(15*(1-t)*(1-t)*t*t*255);
    int b = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);

    return (r << 16) | (g << 8) | b; // RGB olarak döndür
}

static void	handle_pixel(int x, int y, t_fractal *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (map(x, -2, +2, 0, WIDHT) * data->zoom) + data->shift_x;
	c.y = (map(y, -2, +2, 0, HEIGHT) * data->zoom) + data->shift_y;
	while (i < data->iterations_def)
	{
		z = sum_complex(square_complex(z), c);
 
		if ((z.x *z.x) + (z.y *z.y) > data->escape_val)
		{
			color = rainbow_color(i, data->iterations_def);
			my_pixel_put(x, y, &data->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &data->img, WHITE);
}

void	render(t_fractal *data)
{
	int	x;
	int	y;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDHT)
		{
			handle_pixel(x, y, data);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}