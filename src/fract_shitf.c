/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_shitf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:43:25 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/01 02:27:00 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	shift_right(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / WIDHT) * data->zoom;
	data->shift_x -= fractal_shift;
	shift_bytes = shift_pixels * 4;
	y = -1;
	while (++y < HEIGHT)
	{
		row = (unsigned char *)data->img.pixels_ptr + y * WIDHT * 4;
		x = WIDHT * 4;
		while (--x >= shift_bytes)
			row[x] = row[x - shift_bytes];
		x = -1;
		while (++x < shift_pixels)
			handle_pixel(x, y, data);
	}
}

void	shift_left(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / WIDHT) * data->zoom;
	data->shift_x += fractal_shift;
	shift_bytes = shift_pixels * 4;
	y = -1;
	while (++y < HEIGHT)
	{
		row = (unsigned char *)data->img.pixels_ptr + y * WIDHT * 4;
		x = -1;
		while (++x < WIDHT * 4 - shift_bytes)
			row[x] = row[x + shift_bytes];
		x = WIDHT - shift_pixels - 1;
		while (++x < WIDHT)
			handle_pixel(x, y, data);
	}
}

void	shift_up(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	fractal_shift = shift_pixels * (4.0 / HEIGHT) * data->zoom;
	data->shift_y -= fractal_shift;
	shift_bytes = shift_pixels * WIDHT * 4;
	row = (unsigned char *)data->img.pixels_ptr;
	ft_memmove(row, row + shift_bytes, (HEIGHT - shift_pixels) * WIDHT * 4);
	y = HEIGHT - shift_pixels - 1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDHT)
			handle_pixel(x, y, data);
	}
}

void	shift_down(t_fractal *data, int shift_pixels)
{
	int				x;
	int				y;
	int				shift_bytes;
	double			fractal_shift;
	unsigned char	*row;

	shift_bytes = shift_pixels * WIDHT * 4;
	fractal_shift = shift_pixels * (4.0 / HEIGHT) * data->zoom;
	data->shift_y += fractal_shift;
	row = (unsigned char *)data->img.pixels_ptr;
	ft_memmove(row + shift_bytes, row, (HEIGHT - shift_pixels) * WIDHT * 4);
	y = -1;
	while (++y < shift_pixels)
	{
		x = -1;
		while (++x < WIDHT)
			handle_pixel(x, y, data);
	}
}

// [********] her bir yıldız * bir piksel belirtigini sayarsak benim img ptr bunu char *addr olrak soyle ututyormus bir piksel icin bahsediyorum 
// [********] rgba degeri oluyor int 4 byte lik bir alan kapsıyor bu alnı char * icine yazılıyor ben bu icindeki alanı aldım 
// [********] tekra tekra matematik ile hesaplamatansa char * icerigini kaydırdım kayan ksımı yneiden hesapladım boyle boyle 
// [********] islem yuku 800*800 pksel tekrar tekra hesaplamaktansa kaydırılan kısmın klanaı yani bneim uygulamda 200 *800 gibi bir alan hesaplandı sadece
