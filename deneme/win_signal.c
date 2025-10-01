/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:34:44 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/29 02:47:40 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"



int	esc_input(int key, t_fractal *data)
{
	if (key == XK_Escape)
		close_sig(data);
	else if (key == XK_Left)
		data->shift_x += (0.5 * data->zoom);
	else if (key == XK_Right)
		data->shift_x -= (0.5 * data->zoom);
	else if (key == XK_Up)
		data->shift_y += (0.5 * data->zoom);
	else if (key == XK_Down)
		data->shift_y -= (0.5 * data->zoom);
	else if (key == XK_1) // klavyemde + caslımyor degistimeyi unutma
		data->iterations_def += 10;
	else if (key == XK_minus)
		data->iterations_def -= 10;
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
		data->zoom *= 0.95;
	else if (button == Button4)
		data->zoom *= 1.05;
	render(data);
	return (0);
}

// int	motion_sig(int x, int y, t_fractal *data)
// {
// 	if (!ft_strncmp(data->name, "julia", 5))
// 	{
// 		data->julia_x = (map(x,range) * data->zoom) + data->shift_x;
// 		data->julia_y = (map(y, +2, -2, 0, HEIGHT) * data->zoom) + data->shift_y;
// 		render(data);
// 	}
// 	return (0);
// }