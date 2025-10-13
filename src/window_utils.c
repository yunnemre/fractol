/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:02:42 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:10:50 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mutex_convert(t_fractal *data)
{
	if (!data || !data->win)
		return (0);
	if (!ft_strncmp(data->name, "mandelbrot", 10)
		|| !ft_strncmp(data->name, "multibrot", 10))
		return (0);
	if (data->mutex_val == 0)
		data->mutex_val = 1;
	else
		data->mutex_val = 0;
	return (0);
}

void	bonus_sig(int key, t_fractal *data)
{
	if (key == XK_c)
	{
		free(data->palette);
		data->palette = create_pallette(PALETE_SIZE);
	}
	else if (key == XK_d)
	{
		if (data->pow == 6)
			data->pow = 3;
		else
			data->pow = (data->pow + 1) % 7;
		if (data->jul && data->win)
			data->jul->pow = data->pow;
	}
}
