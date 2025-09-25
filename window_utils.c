/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:49 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/25 03:46:05 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx-linux/mlx.h"

int	esc_input(int key, t_fractal *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);	
		free(data->mlx);
		exit(EXIT_SUCCESS);
	}
	else if (key == XK_Left)
		data->shift_x += (0.5 *data->zoom);
	else if (key == XK_Right)
		data->shift_x -= (0.5 *data->zoom);
	else if (key == XK_Up)
		data->shift_y += (0.5 *data->zoom);
	else if (key == XK_Down)
		data->shift_y -= (0.5 *data->zoom);
	else if (key == XK_KP_Add) // klavyemde + caslımyor degistimeyi unutma
		data->iterations_def +=10;
	else if (key == XK_minus)
		data->iterations_def -=10;
		
	render(data);
	return (0);
}

int	close_sig(t_fractal *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	mouse_sig(int button, int x, int y, t_fractal *data)
{
	if (button == Button5)
	{
		data->zoom *=0.95;
	}
	else if (button == Button4)
	{
		data->zoom *=1.05;
	}
	render(data);
	return(0);
}