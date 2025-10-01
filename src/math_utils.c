/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:41:52 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/30 02:54:11 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
// double	map(double unscaled_num, t_range range)
// {
// 	return (
// 		(range.new_max - range.new_min) * (unscaled_num - range.old_min)
// 		/ (range.old_max - range.old_min)+ range.new_min);
// }

double	map(double unscaled_num, double new_min, double new_max,
	double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	// pıw kulanıla bilir ancak chat yavas kacar diyor
	res.y = 2 * z.x * z.y;
	return (res);
}

int mandelbrot(double cx, double cy, int max_iter)
{
    double	x;
    double	y;
    double tmp;
	int		i;
	
	
	x = 0;
	y = 0;
	i = 0;
    while (x * x + y * y <= 4 && i < max_iter)
    {
        tmp = x * x - y * y + cx;
        y = 2 * x * y + cy;
        x = tmp;
        i++;
    }
    return i;
}

int julia(double zx, double zy, int max_iter, double cx, double cy)
{
    int		i;
	double	tmp;
	
	i = 0;
    while (zx * zx + zy * zy <= 4 && i < max_iter)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        i++;
    }
    return i;
}
