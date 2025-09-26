/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:35:14 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 16:15:36 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		c->x = data->julia_x;
		c->y = data->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	rainbow_color(int i, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)i / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) *(1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

static void	handle_pixel(int x, int y, t_fractal *data)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, 0, WIDHT) * data->zoom) + data->shift_x;
	z.y = (map(y, +2, -2, 0, HEIGHT) * data->zoom) + data->shift_y;
	mandel_vs_julia(&z, &c, data);
	while (i < data->iterations_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > data->escape_val)
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
			handle_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}
// eger ben  olceklendirme 4 ve 1 gibi rakamlarla yaparsam sekil 
	//bozulur her kısmı almaz yada herseyi alır fazla render
//hypot(z.x, z.y) cevircen sqrt kulanarak 2 ile karsılartırabilirdin 
//sayıalrn ormali ile ancak yine yavas kacar diyor