/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:41:52 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:16:52 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(double unscaled_num, t_range range)
{
	return ((range.new_max - range.new_min) * (unscaled_num - range.old_min)
		/ (range.old_max - range.old_min) + range.new_min);
}

int	mandelbrot(t_complex c, int max_iter)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	while (x * x + y * y <= 4 && i < max_iter)
	{
		tmp = x * x - y * y + c.x;
		y = 2 * x * y + c.y;
		x = tmp;
		i++;
	}
	return (i);
}

int	julia(t_complex z, int max_iter, double cx, double cy)
{
	int		i;
	double	tmp;

	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + cx;
		z.y = 2 * z.x * z.y + cy;
		z.x = tmp;
		i++;
	}
	return (i);
}

// t_complex	sum_complex(t_complex z1, t_complex z2)
// {
// 	t_complex	res;

// 	res.x = z1.x + z2.x;
// 	res.y = z1.y + z2.y;
// 	return (res);
// }

// t_complex	square_complex(t_complex z)
// {
// 	t_complex	res;

// 	res.x = (z.x * z.x) - (z.y * z.y);
// 	res.y = 2 * z.x * z.y;
// 	return (res);
// }
// double	map(double unscaled_num, double new_min, double new_max,
// 	double old_min, double old_max)
// {
// 	return ((new_max - new_min) * (unscaled_num - old_min)
// 		/ (old_max - old_min) + new_min);
// }
// pıw kulanıla bilir ancak chat yavas kacar diyor