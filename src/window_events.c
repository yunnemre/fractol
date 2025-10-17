/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:49 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/17 15:30:02 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// plus klavyemde + caslımyor degistimeyi unutma
int	expose_hook(t_fractal *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	input_sig(int key, t_fractal *data)
{
	if (key == XK_Escape)
		close_sig(data);
	else if (key == XK_Left || key == XK_Right
		|| key == XK_Down || key == XK_Up)
		return (shift_man(key, data));
	else if (key == XK_1 || key == XK_minus)
		iteration_sig(key, data);
	else if (key == XK_2)
		return (mutex_convert(data));
	else if (key == XK_3)
	{
		data->shift_x = 0.0;
		data->shift_y = 0.0;
		data->zoom = 1.0;
	}
	else if (key == XK_c || key == XK_d)
		bonus_sig(key, data);
	render(data);
	return (0);
}

int	close_sig(t_fractal *data)
{
	if (data->jul)
	{
		mlx_destroy_image(data->jul->mlx, data->jul->img.img_ptr);
		mlx_destroy_window(data->jul->mlx, data->jul->win);
		free(data->jul);
	}
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->palette);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	mouse_sig(int button, int x, int y, t_fractal *data)
{
	t_complex	f;
	t_complex	m;

	if (!data || !data->win)
		return (0);
	f.x = map(x, data->range_x);
	f.y = map(y, data->range_y);
	m.x = f.x * data->zoom + data->shift_x;
	m.y = f.y * data->zoom + data->shift_y;
	if (button == Button5)
		data->zoom *= 0.95;
	else if (button == Button4)
		data->zoom *= 1.05;
	else if (button == Button3)
	{
		if (!ft_strncmp(data->name, "mandelbrot", 10)
			|| !ft_strncmp(data->name, "multibrot", 10))
			return (julia_win_man(x, y, data));
	}
	else if (button == Button1)
		data->zoom *= 0.25;
	data->shift_x = m.x - f.x * data->zoom;
	data->shift_y = m.y - f.y * data->zoom;
	render(data);
	return (0);
}

int	motion_sig(int x, int y, t_fractal *data)
{
	static int	frame = 0;

	if (!data || !data->win)
		return (0);
	frame++;
	if (frame % 5 != 0)
		return (0);
	if (!ft_strncmp(data->name, "julia", 5)
		|| !ft_strncmp(data->name, "multijul", 9))
	{
		if (data->mutex_val != 0)
			return (0);
		data->julia_x = (map(x, data->range_x) * data->zoom) + data->shift_x;
		data->julia_y = (map(y, data->range_y) * data->zoom) + data->shift_y;
		render(data);
	}
	return (0);
}

// julia kasmayı engellem kicin ekranı 8 veya es bir 
//parcay bolup eger
//konumuna gore hazır julai seti veirlebilir ayriyeten
//ready for julia set
//itearsyon sayısına gore bir tane zooma gore bir tane kaydırmaya gore bir tane