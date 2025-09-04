/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:25:50 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/04 14:47:38 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"

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

int	handle_input(int key, t_mlxdata *data)
{
	if (key == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed \n", key);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n", key);
	return (0);
}

int	close_sig(t_mlxdata *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_mlxdata	data;

	if(argc == 1)
		return (helper(1));
	// else
	// 	ft_check_arg(argc, argv, &data); https://www.youtube.com/watch?v=bYS93r6U0zg
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.win = mlx_new_window(data.mlx, 800, 800, "Fractol");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (1);
	}
	mlx_key_hook(data.win,handle_input, &data);
	mlx_hook(data.win, 17, 0, close_sig, &data);
	mlx_loop(data.mlx);
	
	return (0);
}