/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul_win_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:11:29 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/17 15:23:20 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	jul_expose(t_fractal *jul)
{
	if (jul)
		mlx_put_image_to_window(jul->mlx, jul->win, jul->img.img_ptr, 0, 0);
	return (0);
}

int	jul_close_sig(t_fractal **jul_ptr)
{
	t_fractal	*jul;

	if (!jul_ptr || !*jul_ptr)
		return (0);
	jul = *jul_ptr;
	if (jul->img.img_ptr)
		mlx_destroy_image(jul->mlx, jul->img.img_ptr);
	if (jul->win)
		mlx_destroy_window(jul->mlx, jul->win);
	free(jul);
	*jul_ptr = NULL;
	return (0);
}

int	jul_input_sig(int key, t_fractal *jul)
{
	if (!jul || !jul->win)
		return (0);
	if (key == XK_Escape)
		return (jul_close_sig(&jul));
	else if (key == XK_Left || key == XK_Right
		|| key == XK_Down || key == XK_Up)
		return (shift_man(key, jul));
	else if (key == XK_1)
		jul->iterations_def += 10;
	else if (key == XK_minus)
		jul->iterations_def -= 10;
	else if (key == XK_2)
		return (mutex_convert(jul));
	else if (key == XK_3)
	{
		jul->shift_x = 0.0;
		jul->shift_y = 0.0;
		jul->zoom = 1.0;
		jul->iterations_def = 50;
	}
	jul_render(jul);
	return (0);
}

int	jul_mouse_sig(int button, int x, int y, t_fractal *jul)
{
	t_complex	f;
	t_complex	m;

	if (!jul || !jul->win)
		return (0);
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
		if (jul->iterations_def <= PALETE_SIZE - 50)
			jul->iterations_def += 50;
	}
	else if (button == Button2)
		jul->zoom *= 2.5;
	jul->shift_x = m.x - f.x * jul->zoom;
	jul->shift_y = m.y - f.y * jul->zoom;
	jul_render(jul);
	return (0);
}

int	jul_motion_sig(int x, int y, t_fractal *jul)
{
	static int	frame = 0;

	if (!jul || !jul->win)
		return (0);
	frame++;
	if (frame % 5 != 0)
		return (0);
	if (jul->mutex_val != 0)
		return (0);
	jul->julia_x = (map(x, jul->range_x) * jul->zoom) + jul->shift_x;
	jul->julia_y = (map(y, jul->range_y) * jul->zoom) + jul->shift_y;
	jul_render(jul);
	return (0);
}
