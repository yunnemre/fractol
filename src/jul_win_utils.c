/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:11:29 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:13:17 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	jul_close_sig(t_fractal *data)
{
	mlx_destroy_image(data->jul->mlx, data->jul->img.img_ptr);
	mlx_destroy_window(data->jul->mlx, data->jul->win);
	free(data->jul);
	render(data);
	data->jul = NULL;
	return (0);
}

int	jul_input_sig(int key, t_fractal *jul)
{
	if (key == XK_Escape)
		jul_close_sig(jul);
	// else if (key == XK_Left || key == XK_Right
	// 	|| key == XK_Down || key == XK_Up)
	// {
	// 	shift_man(key, jul);
	// 	return (0);
	// }
	else if (key == XK_1)
		jul->iterations_def += 10;
	else if (key == XK_minus)
		jul->iterations_def -= 10;
	jul_render(jul);
	mlx_do_sync(jul->mlx);
	return (0);
}

int	jul_mouse_sig(int button, int x, int y, t_fractal *jul)
{
	t_complex	f;
	t_complex	m;

	f.x = map(x, jul->range_x);
	f.y = map(y, jul->range_y);
	m.x = f.x * jul->zoom + jul->shift_x;
	m.y = f.y * jul->zoom + jul->shift_y;
	if (button == Button5)
		jul->zoom *= 0.95;
	else if (button == Button4)
		jul->zoom *= 1.05;
	else if (button == Button3)
	{
		jul->zoom *= 0.25;
		if (jul->iterations_def * 2 < 1024)
			jul->iterations_def *= 2;
	}
	else if (button == Button2)
		jul->zoom *= 2.5;
	jul->shift_x = m.x - f.x * jul->zoom;
	jul->shift_y = m.y - f.y * jul->zoom;
	jul_render(jul);
	return (0);
}

void	draw_crosshair(t_img *img, int x, int y, int color)
{
	int	i;

	i = -6;
	while (++i <= 5)
		my_pixel_put(x + i, y, img, color);
	i = -6;
	while (++i <= 5)
		my_pixel_put(x, y + i, img, color);
}
