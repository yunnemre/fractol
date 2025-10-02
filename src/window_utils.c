/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:49 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/02 22:23:51 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
int	esc_input(int key, t_fractal *data)
{
	if (key == XK_Escape)
		close_sig(data);
	else if (key == XK_Left)
		shift_left(data, 200);
	else if (key == XK_Right)
		shift_right(data, 200);
	else if (key == XK_Down)
		shift_down(data, 200);
	else if (key == XK_Up)
		shift_up(data, 200);
	else if (key == XK_1) // klavyemde + caslımyor degistimeyi unutma
	{
		data->iterations_def += 10;
		render(data);
		return (0);
	}
	else if (key == XK_minus)
	{
		data->iterations_def -= 10;
		render(data);
		return (0);
	}
	else if (key == XK_2)
	{
		if (data->mutex_val == 0)
			data->mutex_val = 1;
		else
			data->mutex_val = 0;
		return (0);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return (0);
}

int	close_sig(t_fractal *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->palette);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int mouse_sig(int button, int x, int y, t_fractal *data)
{
    double	fx;
	double	fy;
	double	mx;
	double	my;
    //int		tmp;

    if (button == Button5)
	{
		fx = map(x, -2, +2, 0, WIDHT);
		fy = map(y, +2, -2, 0, HEIGHT);
		mx = fx * data->zoom + data->shift_x;
		my = fy * data->zoom + data->shift_y;
		data->zoom *= 0.95;
	}
       
    else if (button == Button4)
	{
		fx = map(x, +2, -2, 0, WIDHT);
		fy = map(y, -2, +2, 0, HEIGHT);
		mx = fx * data->zoom + data->shift_x;
		my = fy * data->zoom + data->shift_y;
		data->zoom *= 1.05;
	}
        
    else
        return 0;
    data->shift_x = mx - fx * data->zoom;
    data->shift_y = my - fy * data->zoom;
	data->iterations_def+= 5;
	render(data);
    return 0;
}

// static void	data_copy(t_fractal *data, t_fractal *copy)
// {
// 	copy->escape_val=data->escape_val;
// 	copy->iterations_def = data->iterations_def;
// 	copy->shift_x = data->shift_x;
// 	copy->shift_y = data->shift_y;
// 	copy->zoom = data->zoom;
// 	copy->palette = data->palette;
// 	copy->mutex_val = data->mutex_val;
// }

// julia kasmayı engellem kicin ekranı 8 veya es bir parcay bolup eger konumuna gore hazır julai seti veirlebilir ayriyeten 
//ready for julia set
//itearsyon sayısına gore bir tane zooma gore bir tane kaydırmaya gore bir tane

int	motion_sig(int x, int y, t_fractal *data)
{
	if (!ft_strncmp(data->name, "julia", 5))
	{
		if (data->mutex_val != 0)
			return (0);
		data->julia_x = (map(x, -2, +2, 0, WIDHT) * data->zoom) + data->shift_x;
		data->julia_y = (map(y, +2, -2, 0, HEIGHT) * data->zoom) + data->shift_y;
		render(data);
	}
	return (0);
}