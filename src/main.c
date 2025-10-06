/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:25:50 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:16:19 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int	expose_hook(t_fractal *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

static double	ft_atodbl(const char *nptr)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0.0;
	fractional_part = 0.0;
	sign = 1;
	pow = 1.0;
	while (*nptr && (*nptr == ' ' || (9 <= *nptr && *nptr <= 13)))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr != '.' && *nptr)
		integer_part = integer_part * 10 + (*nptr++ - '0');
	if ('.' == *nptr)
		++nptr;
	while (*nptr && ft_isdigit(*nptr))
	{
		fractional_part = fractional_part * 10 + (*nptr++ - '0');
		pow *= 10;
	}
	return (sign * (integer_part + fractional_part / pow));
}

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
		data_init(&fract);
		render(&fract);
		mlx_hook(fract.win, 17, 0, close_sig, &fract);
		mlx_hook(fract.win, 4, 1L << 2, mouse_sig, &fract);
		mlx_hook(fract.win, 6, 1L << 6, motion_sig, &fract);
		mlx_hook(fract.win, 12, 1L << 15, expose_hook, &fract);
		mlx_key_hook(fract.win, input_sig, &fract);
		mlx_loop(fract.mlx);
	}
	else
		ft_err_man();
	return (0);
}
//mlx_loop_hook(fract.mlx, render, &fract);
