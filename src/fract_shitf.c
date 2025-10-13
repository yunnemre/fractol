/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_shitf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:43:25 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:10:08 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	shift_right(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / data->range_x.old_max) * data->zoom;
	data->shift_x -= fractal_shift;
	shift_bytes = shift_pixels * 4;
	y = -1;
	while (++y < (int)(data->range_y.old_max))
	{
		row = (unsigned char *)data->img.pixels_ptr + y
			* (int)(data->range_x.old_max) * 4;
		x = (int)(data->range_x.old_max) * 4;
		while (--x >= shift_bytes)
			row[x] = row[x - shift_bytes];
		x = -1;
		while (++x < shift_pixels)
			handle_pixel(x, y, data);
	}
}

static void	shift_left(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / (data->range_x.old_max)) * data->zoom;
	data->shift_x += fractal_shift;
	shift_bytes = shift_pixels * 4;
	y = -1;
	while (++y < (int)(data->range_y.old_max))
	{
		row = (unsigned char *)data->img.pixels_ptr + y
			* (int)(data->range_x.old_max) * 4;
		x = -1;
		while (++x < (int)(data->range_x.old_max) * 4 - shift_bytes)
			row[x] = row[x + shift_bytes];
		x = (int)(data->range_x.old_max) - shift_pixels - 1;
		while (++x < (int)(data->range_x.old_max))
			handle_pixel(x, y, data);
	}
}

static void	shift_up(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / (data->range_y.old_max)) * data->zoom;
	data->shift_y -= fractal_shift;
	shift_bytes = shift_pixels * (int)(data->range_x.old_max) * 4;
	row = (unsigned char *)data->img.pixels_ptr;
	ft_memmove(row, row + shift_bytes,
		((int)(data->range_y.old_max) - shift_pixels)
		* (int)(data->range_x.old_max) * 4);
	y = (int)(data->range_y.old_max) - shift_pixels - 1;
	while (++y < (int)(data->range_y.old_max))
	{
		x = -1;
		while (++x < (int)(data->range_x.old_max))
			handle_pixel(x, y, data);
	}
}

static void	shift_down(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / (data->range_y.old_max)) * data->zoom;
	data->shift_y += fractal_shift;
	shift_bytes = shift_pixels * (int)(data->range_x.old_max) * 4;
	row = (unsigned char *)data->img.pixels_ptr;
	ft_memmove(row + shift_bytes, row,
		((int)(data->range_y.old_max) - shift_pixels)
		* (int)(data->range_x.old_max) * 4);
	y = -1;
	while (++y < shift_pixels)
	{
		x = -1;
		while (++x < (int)(data->range_x.old_max))
			handle_pixel(x, y, data);
	}
}

int	shift_man(int key, t_fractal *data)
{
	if (key == XK_Left)
		shift_left(data, 200);
	else if (key == XK_Right)
		shift_right(data, 200);
	else if (key == XK_Down)
		shift_down(data, 200);
	else if (key == XK_Up)
		shift_up(data, 200);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

//mlx_do_sync(data->mlx); bana yavas geldi ama test edilcek
// static void print_all_pixels(t_img *img)
// {
// 	int y = -1;
// 	int x;
// 	unsigned char *p;	
//     while (++y < HEIGHT)
//     {
// 		x = -1;
//         while ( ++x < WIDHT)
//         {
//p = (unsigned char *)img->pixels_ptr + y * img->line + x * (img->bpp / 8);
// 			if (p[0] > 0 && p[1])
// 				printf("%d %d %d %d \n",p[0],p[1],p[2],p[3]);
//         }
//     }
//printf("%f %f",data->shift_x, fractal_shift);
//print_all_pixels(&data->img);
// }
// [********] her bir yıldız * bir piksel belirtigini sayarsak benim img ptr 
//bunu char *addr olrak soyle ututyormus bir piksel icin bahsediyorum 
// [********] rgba degeri oluyor int 4 byte lik bir alan kapsıyor bu alnı 
//char * icine yazılıyor ben bu icindeki alanı aldım 
// [********] tekra tekra matematik ile hesaplamatansa 
//char * icerigini kaydırdım kayan ksımı yneiden hesapladım boyle boyle 
// [********] islem yuku 800*800 pksel tekrar tekra hesaplamaktansa 
//kaydırılan kısmın klanaı yani bneim uygulamda 200 *800 gibi 
//bir alan hesaplandı sadece