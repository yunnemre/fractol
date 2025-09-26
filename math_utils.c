/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:41:52 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 15:58:07 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
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
