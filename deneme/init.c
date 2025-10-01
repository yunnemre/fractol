#include "fract.h"

static void	data_init(t_fractal *data)
{
	data->escape_val = 4;
	data->iterations_def = 42;
	data->shift_x = 0.0;
	data->shift_y = 0.0;
	data->zoom = 2.10;
}


void	win_init(t_fractal *data)
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
	data_init(data);
}
