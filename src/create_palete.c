/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:37:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/19 17:13:04 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static int	create_rgb3(t_rgb rgb)
{
	double	t;

	t = rgb.t;
	rgb.r = (double)(9 * (1 - t) * t * t * t * 25);
	rgb.g = (double)(15 * (1 - t) * (1 - t) * t * t * 255);
	rgb.b = (double)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 25);
	return (((rgb.r & 0xFF)) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF) << 16);
}

static int	create_rgb2(t_rgb rgb)
{
	double	t;

	t = rgb.t;
	rgb.r = (double)(9 * (1 - t) * t * t * t * 255);
	rgb.g = (double)(15 * (1 - t) * (1 - t) * t * t * 255);
	rgb.b = (double)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (((rgb.r & 0xFF) << 16) | ((rgb.g & 0xFF) << 8) | (rgb.b & 0xFF));
}

static int	create_rgb1(t_rgb rgb)
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
