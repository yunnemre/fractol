/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 03:41:52 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/17 15:28:37 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, t_range range)
{
	return ((range.new_max - range.new_min) * (unscaled_num - range.old_min)
		/ (range.old_max - range.old_min) + range.new_min);
}

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
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

int	multibrot(t_complex c, int max_iter, int power)
{
	t_complex	z;
	int			i;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < max_iter)
	{
		if (power == 3)
			power3(&z, c);
		else if (power == 4)
			power4(&z, c);
		else if (power == 5)
			power5(&z, c);
		else if (power == 6)
			power6(&z, c);
		i++;
	}
	return (i);
}

int	multi_jul(t_complex z, int max_iter, t_complex c, int power)
{
	int	i;

	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i < max_iter)
	{
		if (power == 3)
			power3(&z, c);
		else if (power == 4)
			power4(&z, c);
		else if (power == 5)
			power5(&z, c);
		else if (power == 6)
			power6(&z, c);
		i++;
	}
	return (i);
}
