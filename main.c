/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:25:50 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/25 03:22:05 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"


// int	handle_input(int key, t_mlxdata *data)
// {
// 	if (key == XK_Escape)
// 	{
// 		ft_printf("The %d key (ESC) has been pressed \n", key);
// 		mlx_destroy_window(data->mlx, data->win);
// 		mlx_destroy_display(data->mlx);
// 		free(data->mlx);
// 		exit(1);
// 	}
// 	ft_printf("The %d key has been pressed\n", key);
// 	return (0);
// }

// int	close_sig(t_mlxdata *data)
// {
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// }

int	main(int argc, char **argv)
{
	t_fractal	fract;
	
	if(2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10) 
	 	|| 4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		fract.name = argv[1];
		fractal_init(&fract);
		render(&fract);
		mlx_hook(fract.win, 17, 0, close_sig, &fract);
		mlx_hook(fract.win, 4, 1L<<2, mouse_sig, &fract);
		mlx_key_hook(fract.win,esc_input,&fract);
		
		mlx_loop(fract.mlx);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
		// https://www.youtube.com/watch?v=bYS93r6U0zg
	
	return (0);
}

// typedef struct s_complex
// {
// 	double real;
	
// 	double i;
// } t_complex;



// t_complex z;
// 	t_complex c;
// 	double tmp_real;

// 	z.real = 0;
// 	z.i =0;

// 	c.real = 0.25;
// 	c.i = 0.4;
// 	for (int i = 0; i < 42; i++)
// 	{
// 		tmp_real = (z.real *z.real) - (z.i * z.i);
// 		z.i = 2 * z.real * z.i;
// 		z.real = tmp_real;

// 		z.real += c.real;
// 		z.i += c.i;
// 		printf("iteartion number ->%d , real %f , imaginory %f \n",i , z.real,z.i);
// 	}

// void ft_check_arg(int argc, char **argv, t_mlxdata *data)
// {
// 	if (argc == 2)
// 	{
// 		if (ft_strncmp(argv[1] ,"mandelbrot", 9))
// 		{
// 			data->fractal_type = 1;
// 			return ;
// 		}
// 		if (ft_strncmp(argv[1] ,"julia", 5))
// 		{
// 			data->fractal_type = 2;
// 			return ;
// 		}
// 	}
// 	else if (argc == 4)
// 	{
// 		if (!ft_strncmp(argv[1] ,"julia", 5))
// 			return (helper(1));
// 		data->fractal_type = 2;
		
// 	}
	
// }

// data.mlx = mlx_init();
// 		if (data.mlx == NULL)
// 			return (1);
// 		data.win = mlx_new_window(data.mlx, 800, 800, "Fractol");
// 		if (data.win == NULL)
// 		{
// 			mlx_destroy_display(data.mlx);
// 			free(data.mlx);
// 			return (1);
// 		}
// 		mlx_key_hook(data.win,handle_input, &data);
// 		mlx_hook(data.win, 17, 0, close_sig, &data);