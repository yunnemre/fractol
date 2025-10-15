/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:37:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/15 20:13:32 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

int	create_rgb3(t_rgb rgb)
{
	double	t;

	t = rgb.t;
	rgb.r = (double)(9 * (1 - t) * t * t * t * 25);
	rgb.g = (double)(15 * (1 - t) * (1 - t) * t * t * 255);
	rgb.b = (double)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 25);
	return (((rgb.r & 0xFF)) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF) << 16);
}

int	create_rgb2(t_rgb rgb)
{
	double	s;
	double	h;

	s = rgb.t;
	h = fmod(pow(360.0 * s, 1.5), 360.0);
	rgb.r = (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0)))) + 1.4749
		* (28.0 + (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0))))
			* cos(h * M_PI / 180.0));
	rgb.g = (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0)))) - 0.2280
		* (28.0 + (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0))))
			* cos(h * M_PI / 180.0))
		- 0.3600 * (28.0 + (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0))))
			* sin(h * M_PI / 180.0));
	rgb.b = (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0)))) + 0.0
		* (28.0 + (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0))))
			* cos(h * M_PI / 180.0)) + 0.8310
		* (28.0 + (75.0 - (75.0 * (1 - pow(cos(M_PI * s), 2.0))))
			* sin(h * M_PI / 180.0));

	return ((int)rgb.r | ((int)rgb.g << 8) | ((int)rgb.b << 16));
}

int	create_rgb1(t_rgb rgb)
{
	double	t;

	t = rgb.t;
	rgb.r = (double)(9 * (1 - t) * t * t * t * 255);
	rgb.g = (double)(15 * (1 - t) * (1 - t) * t * t * 25);
	rgb.b = (double)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 155);
	return (((rgb.r & 0xFF) << 16) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF));
}

int	*create_pallette(int max_iter)
{
	static int	mod = 0;
	t_rgb		rgb;
	int			*palette;
	int			i;

	palette = malloc(sizeof(int) * (max_iter + 1));
	if (!palette)
		return (0);
	i = -1;
	while (++i < max_iter)
	{
		rgb.t = (double)i / (double)max_iter;
		if (mod == 0)
			palette[i] = create_rgb1(rgb);
		else if (mod == 1)
			palette[i] = create_rgb2(rgb);
		else if (mod == 2)
			palette[i] = create_rgb3(rgb);
	}
	mod = (mod + 1) % 3;
	return (palette);
}

// int	*create_pallette(int max_iter)
// {
// 	static int	mod = 0;
// 	t_rgb		rgb;
// 	int			*palette;
// 	int			i;

// 	i = -1;
// 	palette = malloc(sizeof(int) * (max_iter + 1));
// 	if (!palette)
// 		return (0);
// 	while (++i < max_iter)
// 	{
// 		rgb.t = (double)i / (double)max_iter;
// 		if (mod == 0)
// 			palette[i] = create_rgb1(rgb);
// 		else if (mod == 1)
// 			palette[i] = create_rgb2(rgb);
// 		else if (mod == 2)
// 			palette[i] = create_rgb3(rgb);
// 	}
// 	mod = (mod + 1) % 3;
// 	return (palette);
// }


// int	create_rgb1(t_rgb rgb)
// {
// 	double	t = rgb.t;

// 	// t = pow(t, 0.7); // istersen ufak yumuşatma ekleyebilirsin (isteğe bağlı)

// 	rgb.r = (int)(255 * (1.0 - t) * t * t * t);
// 	rgb.g = (int)(255 * (1.0 - t) * (1.0 - t) * t * t);
// 	rgb.b = (int)(255 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t);

// 	return ((rgb.r << 16) | (rgb.g << 8) | rgb.b);
// }

// int create_rgb(t_rgb rgb)
// {
//     return (((int)rgb.r & 0xFF) << 16) | (((int)rgb.g & 0xFF) << 8) | ((int)rgb.b & 0xFF);
// }


// int *create_pallette(int max_iter)
// {
//     t_rgb rgb;
//     int *palette;
//     int i;

//     palette = malloc(sizeof(int) * max_iter);
//     if (!palette)
//         return (0);

//     i = -1;
//     while (++i < max_iter)
//     {
//         double t = (double)i / (double)max_iter;
//         rgb.r = (int)(9 * (1 - t) * t * t * t * 255);
//         rgb.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
//         rgb.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // 25 -> 255

//         palette[i] = create_rgb(rgb);
//     }
//     return palette;
// }



// /#include <fcntl.h>
// static int	lch_to_rgb(double L, double C, double H)
// {
// 	double a, b;
// 	double r, g, bl;

// 	// LCH → Lab → RGB dönüşümü
// 	a = C * cos(H * M_PI / 180.0);
// 	b = C * sin(H * M_PI / 180.0);

// 	r = L + 1.4749 * a;
// 	g = L - 0.2280 * a - 0.3600 * b;
// 	bl = L + 0.0 * a + 0.8310 * b;

// 	// clamp
// 	if (r < 0) r = 0; 
// 	if (r > 255) r = 255;
// 	if (g < 0) g = 0; 
// 	if (g > 255) g = 255;
// 	if (bl < 0) bl = 0; 
// 	if (bl > 255) bl = 255;
// 	return ((int)r | ((int)g << 8) | ((int)bl << 16));
// }

// static int create_rgb(double r, double g,double b)
// {
//     return (((int)r & 0xFF) << 16) | (((int)g & 0xFF) << 8) | ((int)b & 0xFF);
// }

// void	handle_pixel(int x, int y, t_fractal *data)
// {
// 	t_complex	z;
// 	t_complex	j;
// 	int			i;
// 	double		s, v, L, C, H;
// 	int			color;

// 	z.x = (map(x, data->range_x) * data->zoom) + data->shift_x;
// 	z.y = (map(y, data->range_y) * data->zoom) + data->shift_y;

// 	if (!ft_strncmp(data->name, "julia", 5))
// 		i = julia(z, data->iterations_def, data->julia_x, data->julia_y);
// 	else if (!ft_strncmp(data->name, "multijul", 9))
// 	{
// 		j.x = data->julia_x;
// 		j.y = data->julia_y;
// 		i = multi_jul(z, data->iterations_def, j, data->pow);
// 	}
// 	else if (!ft_strncmp(data->name, "multibrot", 10))
// 		i = multibrot(z, data->iterations_def, data->pow);
// 	else
// 		i = mandelbrot(z, data->iterations_def);

// 	if (i == data->iterations_def)
// 	{
// 		my_pixel_put(x, y, &data->img, BLACK); // siyah
// 		return ;
// 	}

// 	// --- LCH COLORING ---
// 	s = (double)i / (double)data->iterations_def;
// 	v = 1 - pow(cos(M_PI * s), 2.0);
// 	L = 75.0 - (75.0 * v);
// 	C = 28.0 + (75.0 - (75.0 * v));
// 	H = fmod(pow(360.0 * s, 1.5), 360.0);

// 	color = lch_to_rgb(L, C, H);
// 	// color = lch_to_rgb(L, H, C);
// 	// color = lch_to_rgb(H, L, C);
// 	// color = lch_to_rgb(H, C, L);
// 	// color = lch_to_rgb(C, H, L);
// 	// color = lch_to_rgb(C, L, H);
// 	my_pixel_put(x, y, &data->img, color);
// }

// int main (void)
// {
// 	int *ss =create_pallette(768);
// 	int i = 0;
// 	while(++i < 256)
//  	{
// 			printf("%p\n",ss[i]);
// 	}
// 	return (0);
// }