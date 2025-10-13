/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:25:50 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:10:29 by ydinler          ###   ########.fr       */
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

// mlx_hook(fract.win, FocusIn, 0, focus_in_handler,&fract);
// mlx_hook(fract.win, FocusOut, 0, focus_out_handler, &fract);
//mlx_put_image_to_window(fract.mlx, fract.win, fract.img.img_ptr, 0, 0);
//mlx_loop_hook(fract.mlx, render, &fract);
// mlx_hook(fract.win, 17, 0, close_sig, &fract);
// mlx_hook(fract.win, 4, 1L << 2, mouse_sig, &fract);
// mlx_hook(fract.win, 6, 1L << 6, motion_sig, &fract);
// mlx_hook(fract.win, 12, 1L << 15, expose_hook, &fract);
// mlx_key_hook(fract.win, input_sig, &fract);
// int focus_in_handler(t_fractal *data)
// {
//     data->focused = 1;
//     return (0);
// }

// int focus_out_handler(t_fractal *data)
// {
//     data->focused = 0;
//     return (0);
// }