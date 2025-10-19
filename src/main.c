/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:25:50 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/19 17:09:32 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	hook_event_add(t_fractal *data)
{
	mlx_hook(data->win, DestroyNotify, NoEventMask, close_sig, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_sig, data);
	mlx_hook(data->win, MotionNotify, PointerMotionMask, motion_sig, data);
	mlx_hook(data->win, Expose, ExposureMask, expose_hook, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, input_sig, data);
}

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 11))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 6))
		|| (4 == argc && !ft_strncmp(argv[1], "multijul", 9))
		|| (2 == argc && !ft_strncmp(argv[1], "multibrot", 10)))
	{
		fract.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 6)
			|| !ft_strncmp(argv[1], "multijul", 9))
		{
			if (!ft_isvalid_double(argv[2]) || !ft_isvalid_double(argv[3]))
				start_helper();
			fract.julia_x = ft_atodbl(argv[2]);
			fract.julia_y = ft_atodbl(argv[3]);
		}
		data_init(&fract);
		render(&fract);
		menu_helper();
		hook_event_add(&fract);
		mlx_loop(fract.mlx);
	}
	else
		start_helper();
	return (0);
}
