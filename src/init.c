/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 01:26:00 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/07 01:07:52 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

static void	map_init(t_range *range, int xory)
{
	if (xory)
	{
		range->new_max = +2;
		range->new_min = -2;
		range->old_max = WIDHT;
	}
	else
	{
		range->new_max = -2;
		range->new_min = +2;
		range->old_max = HEIGHT;
	}
	range->old_min = 0;
}

static void	fractal_init(t_fractal *data)
{
	data->escape_val = 4;
	data->iterations_def = 40;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 1.0;
	data->palette = create_pallette(512);
	data->mutex_val = 0;
	if (!ft_strncmp(data->name, "julia", 5))
		data->mutex_val = 1;
	map_init(&data->range_x, 1);
	map_init(&data->range_y, 0);
	data->jul = NULL;
}

void	data_init(t_fractal *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (malloc_error());
	data->win = mlx_new_window(data->mlx, WIDHT, HEIGHT, data->name);
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.img_ptr = mlx_new_image(data->mlx, WIDHT, HEIGHT);
	if (data->img.img_ptr == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		malloc_error();
	}
	data->img.pixels_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line, &data->img.endian);
	fractal_init(data);
}

// static void	map_init(t_range *range)
// {
// 	range->min_wd = -2.0;
// 	range->max_wd = 2.0;
// 	range->min_hg = -2.0; // veya -1.5
// 	range->max_hg = 2.0;

// 	range->scale_x = (range->max_wd - range->min_wd) / WIDHT;
// 	range->scale_y = (range->max_hg - range->min_hg) / HEIGHT;
// }