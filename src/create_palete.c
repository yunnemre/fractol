/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:37:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:05:22 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include  <math.h>
int	create_rgb(int r, int g, int b)
{
	return (((r & 0xFF)) | ((g & 0xFF) << 8) | (b & 0xFF) << 16);
}

int	*create_pallette(int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;
	int		*palette;
	int		i;

	i = -1;
	palette = malloc(sizeof(int) * max_iter);
	if (!palette)
		return (0);
	while (++i < max_iter)
	{
		t = (double)i / (double)max_iter;
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		palette[i] = create_rgb(r, g, b);
	}
	return (palette);
}

// static int	hsl_to_rgb(double h, double s, double l)
// {
// 	double	r, g, b, c, x, m;

// 	c = (1 - fabs(2 * l - 1)) * s;
// 	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
// 	m = l - c / 2;

// 	if (h < 60) { r = c; g = x; b = 0; }
// 	else if (h < 120) { r = x; g = c; b = 0; }
// 	else if (h < 180) { r = 0; g = c; b = x; }
// 	else if (h < 240) { r = 0; g = x; b = c; }
// 	else if (h < 300) { r = x; g = 0; b = c; }
// 	else { r = c; g = 0; b = x; }

// 	return ((int)((r + m) * 255) | ((int)((g + m) * 255) << 8) | ((int)((b + m) * 255) << 16));
// }



// int	lerp_rgb(int c1, int c2, double t)
// {
// 	int	r1 = c1 & 0xFF;
// 	int	g1 = (c1 >> 8) & 0xFF;
// 	int	b1 = (c1 >> 16) & 0xFF;
// 	int	r2 = c2 & 0xFF;
// 	int	g2 = (c2 >> 8) & 0xFF;
// 	int	b2 = (c2 >> 16) & 0xFF;

// 	int	r = r1 + (r2 - r1) * t;
// 	int	g = g1 + (g2 - g1) * t;
// 	int	b = b1 + (b2 - b1) * t;

// 	return (r | (g << 8) | (b << 16));
// }

// int	get_ocean_color(double t)
// {
// 	if (t < 0.25)
// 		return lerp_rgb(0x000022, 0x003366, t / 0.25); // lacivert → koyu mavi
// 	else if (t < 0.5)
// 		return lerp_rgb(0x003366, 0x0088FF, (t - 0.25) / 0.25); // koyu mavi → mavi
// 	else if (t < 0.75)
// 		return lerp_rgb(0x0088FF, 0x00FFD0, (t - 0.5) / 0.25); // mavi → turkuaz
// 	else
// 		return lerp_rgb(0x00FFD0, 0xFFFFFF, (t - 0.75) / 0.25); // turkuaz → beyaz
// }
// int	get_sunset_color(double t)
// {
// 	if (t < 0.20)
// 		return lerp_rgb(0x1A0033, 0x660066, t / 0.20); // lacivert → mor
// 	else if (t < 0.40)
// 		return lerp_rgb(0x660066, 0xFF0099, (t - 0.20) / 0.20); // mor → pembe
// 	else if (t < 0.60)
// 		return lerp_rgb(0xFF0099, 0xFF6600, (t - 0.40) / 0.20); // pembe → turuncu
// 	else if (t < 0.80)
// 		return lerp_rgb(0xFF6600, 0xFFFF00, (t - 0.60) / 0.20); // turuncu → sarı
// 	else
// 		return lerp_rgb(0xFFFF00, 0xFFFFFF, (t - 0.80) / 0.20); // sarı → beyaz
// }

// int	get_rainbow_color(double t)
// {
// 	if (t < 0.17)
// 		return lerp_rgb(0xFF0000, 0xFF7F00, t / 0.17); // kırmızı → turuncu
// 	else if (t < 0.34)
// 		return lerp_rgb(0xFF7F00, 0xFFFF00, (t - 0.17) / 0.17); // turuncu → sarı
// 	else if (t < 0.51)
// 		return lerp_rgb(0xFFFF00, 0x00FF00, (t - 0.34) / 0.17); // sarı → yeşil
// 	else if (t < 0.68)
// 		return lerp_rgb(0x00FF00, 0x0000FF, (t - 0.51) / 0.17); // yeşil → mavi
// 	else if (t < 0.85)
// 		return lerp_rgb(0x0000FF, 0x8B00FF, (t - 0.68) / 0.17); // mavi → mor
// 	else
// 		return lerp_rgb(0x8B00FF, 0xFFFFFF, (t - 0.85) / 0.15); // mor → beyaz
// }
// int	*create_pallette(int max_iter)
// {
// 	int	*palette = malloc(sizeof(int) * max_iter);
// 	int i = -1;
// 	while(++i < 150)
// 		palette[i] = get_rainbow_color((double)i / max_iter);
// 	i--;
// 	while (++i < 300)
// 		palette[i] = get_ocean_color((double)i / max_iter);
// 	i--;
// 	while (++i < 513)
// 		palette[i] = get_sunset_color((double)i / max_iter);
// 	return (palette);
// }