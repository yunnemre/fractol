/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:33:58 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:10:35 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	power3(t_complex *z, t_complex c)
{
	double	tmp;

	tmp = (z->x * z->x * z->x) - 3 * z->x * z->y * z->y + c.x;
	z->y = 3 * z->x * z->x * z->y - (z->y * z->y * z->y) + c.y;
	z->x = tmp;
}

void	power4(t_complex *z, t_complex c)
{
	double	tmp;

	tmp = (z->x * z->x * z->x * z->x) - 6 * (z->x * z->x) * (z->y * z->y)
		+ (z->y * z->y * z->y * z->y) + c.x;
	z->y = 4 * (z->x * z->x * z->x * z->y)
		- 4 * (z->x * z->y * z->y * z->y) + c.y;
	z->x = tmp;
}

void	power5(t_complex *z, t_complex c)
{
	double	tmp;

	tmp = (z->x * z->x * z->x * z->x * z->x)
		- 10 * (z->x * z->x * z->x * z->y * z->y)
		+ 5 * (z->x * z->y * z->y * z->y * z->y) + c.x;
	z->y = 5 * (z->x * z->x * z->x * z->x * z->y)
		- 10 * (z->x * z->x * z->y * z->y * z->y)
		+ (z->y * z->y * z->y * z->y * z->y) + c.y;
	z->x = tmp;
}

void	power6(t_complex *z, t_complex c)
{
	double	tmp;

	tmp = (z->x * z->x * z->x * z->x * z->x * z->x)
		- 15 * (z->x * z->x * z->x * z->x * z->y * z->y)
		+ 15 * (z->x * z->x * z->y * z->y * z->y * z->y)
		- (z->y * z->y * z->y * z->y * z->y * z->y) + c.x;
	z->y = 6 * (z->x * z->x * z->x * z->x * z->x * z->y)
		- 20 * (z->x * z->x * z->x * z->y * z->y * z->y)
		+ 6 * (z->x * z->y * z->y * z->y * z->y * z->y) + c.y;
	z->x = tmp;
}
