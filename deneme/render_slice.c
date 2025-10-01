#include "fract.h"

#define SLICE_HEIGHT 20
#define COLOR_TABLE_SIZE 1000

int create_rgb(int r, int g, int b)
{
    return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

int	*create_pallette(int max_iter)
{
	double t;
	int r;
	int g;
	int b;
	int *palette;
	int	i;

	i = -1;
	palette = malloc(sizeof(int) * max_iter);
	if(!palette)
		return (0);
	while (i++ < max_iter)
	{
		t = (double)i / (double)max_iter;  // 0.0 → 1.0
        r = (int)(9 * (1 - t) * t * t * t * 255);
        g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
        b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		palette[i] = create_rgb(r,g,b);
	}
	return (palette);
}


static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset = (y * img->line) + (x * (img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *data)
{
    if (!ft_strncmp(data->name, "julia", 5))
    {
        c->x = data->julia_x;
        c->y = data->julia_y;
    }
    else
    {
        c->x = z->x;
        c->y = z->y;
    }
}

static void handle_pixel(int x, int y, t_fractal *data)
{
    t_complex	z;
	t_complex	c;
	t_range		range;
	int			i;

	range.new_max=-2;
	range.new_min=+2;
	range.old_min=0;
	range.old_min=HEIGHT;
	i = 0;
	z.x = (map(x, range) * data->zoom) + data->shift_x;
	range.new_max=+2;
	range.new_min=-2;
	z.y = (map(y, range) * data->zoom) + data->shift_y;
	mandel_vs_julia(&z, &c, data);
    while (i < data->iterations_def)
    {
        double tmp_x = z.x * z.x - z.y * z.y + c.x;
        z.y = 2 * z.x * z.y + c.y;
        z.x = tmp_x;

        if ((z.x * z.x + z.y * z.y) > data->escape_val)
        {
            my_pixel_put(x, y, &data->img, data->palette[i % data->iterations_def]);
            return;
        }
        i++;
    }
    my_pixel_put(x, y, &data->img, WHITE);
}
void	render(t_fractal *data)
{
	int	x;
	int	y;

	mlx_clear_window(data->mlx, data->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDHT)
			handle_pixel(x, y, data);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

// Slice rendering
// int render_slice(t_fractal *data)
// {
//     static int y_start = 0;

//     init_color_table(data->iterations_def);

//     double dx = (4.0 / WIDHT) * data->zoom;
//     double dy = (4.0 / HEIGHT) * data->zoom;
//     double zx_start = -2.0 * data->zoom + data->shift_x;
//     double zy_start = -2.0 * data->zoom + data->shift_y;

//     int y_end = y_start + SLICE_HEIGHT;
//     if (y_end > HEIGHT)
//         y_end = HEIGHT;

//     for (int y = y_start; y < y_end; y++)
//         for (int x = 0; x < WIDHT; x++)
//             handle_pixel(x, y, data);

//     mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
//     mlx_do_sync(data->mlx); // anında ekrana yansıt

//     return (0);
// }
