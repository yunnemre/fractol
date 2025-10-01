/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:35:44 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/29 02:46:25 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	main(int argc, char **argv)
{
	t_fractal	fract;

	if ((2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (4 == argc && !ft_strncmp(argv[1], "julia", 5)))
	{
		fract.name = argv[1];
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			if (!ft_isvalid_double(argv[2]) || !ft_isvalid_double(argv[3]))
				ft_err_man();
			fract.julia_x = ft_atodbl(argv[2]);
			fract.julia_y = ft_atodbl(argv[3]);
		}
		win_init(&fract);
		
		render(&fract);
		mlx_hook(fract.win, 17, 0, close_sig, &fract);
		mlx_hook(fract.win, 4, 1L << 2, mouse_sig, &fract);
		//mlx_hook(fract.win, 6, 1L << 6, motion_sig, &fract);
		mlx_key_hook(fract.win, esc_input, &fract);
		//mlx_loop_hook(fract.mlx, render, &fract);
		
		mlx_loop(fract.mlx);
	}
	else
		ft_err_man();
	return (0);
}
