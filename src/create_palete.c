/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_palete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 02:37:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/01 03:00:47 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
int create_rgb(int r, int g, int b)
{
    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

int	*create_pallette(int max_iter)
{
	max_iter = 500;
	double t;
	int r;
	int g;
	int b;
	int *palette;
	int	i;

	i = -1;
	palette = malloc(sizeof(int) * max_iter);
	if(!palette)
		return (0);
	while (++i < max_iter)
	{
		t = (double)i / (double)max_iter;  // 0.0 → 1.0
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		palette[i] = create_rgb(r,g,b);
	}
	return (palette);
}