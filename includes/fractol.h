/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:26:38 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/19 17:10:07 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"
# include "libft.h"
# include <math.h>
# define WIDHT	800
# define HEIGHT	800

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define SILVER      0xC0C0C0

# define PALETE_SIZE 512

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct s_rgb
{
	double		t;
	int 		r;
	int 		g;
	int 		b;
}	t_rgb;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_range
{
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}	t_range;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line;
}	t_img;

typedef struct s_fractal
{
	char				*name;
	void				*mlx;
	void				*win;
	t_img				img;
	int					pow;
	int					*palette;
	struct s_fractal	*jul;
	t_range				range_x;
	t_range				range_y;
	double				escape_val;
	int					iterations_def;
	double				shift_x;
	double				shift_y;
	double				zoom;
	double				julia_x;
	double				julia_y;
	int					mutex_val;
}	t_fractal;

// window_events.c
int			close_sig(t_fractal *data);
int			input_sig(int key, t_fractal *data);
int			mouse_sig(int button, int x, int y, t_fractal *data);
int			motion_sig(int x, int y, t_fractal *data);
int			expose_hook(t_fractal *data);

// windpw_utils.c
int			mutex_convert(t_fractal *data);
void		bonus_sig(int key, t_fractal *data);
void		iteration_sig(int key, t_fractal *data);

// init.c
void		data_init(t_fractal *data);

//render.c
void		render(t_fractal *data);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		handle_pixel(int x, int y, t_fractal *data);

///math_utils.c
double		map(double unscaled_num, t_range range);
int			julia(t_complex z, int max_iter, double cx, double cy);
int			mandelbrot(t_complex c, int max_iter);
int			multibrot(t_complex c, int max_iter, int power);
int			multi_jul(t_complex z, int max_iter, t_complex c, int power);

// power.calc.c
void		power3(t_complex *z, t_complex c);
void		power4(t_complex *z, t_complex c);
void		power5(t_complex *z, t_complex c);
void		power6(t_complex *z, t_complex c);

//utils.c
double		ft_atodbl(const char *nptr);
int			ft_isvalid_double(const char *s);

//CREATE_PALLETTE
int			*create_pallette(int max_iter);

//shıtf fract.c
int			shift_man(int key, t_fractal *data);

// julia_mlx.c
int			julia_win_man(int x, int y, t_fractal *data);
void		julia_win(int x, int y, t_fractal *data);
void		jul_render(t_fractal *jul);
void		jul_pixel(int x, int y, t_fractal *jul);
void		draw_crosshair(t_img *img, int x, int y, int color);

//julia_win_utils.c
int			jul_close_sig(t_fractal **jul);
int			jul_input_sig(int key, t_fractal *jul);
int			jul_mouse_sig(int button, int x, int y, t_fractal *data);
int			jul_expose(t_fractal *jul);

//helper.c
void		malloc_error(void);
void		start_helper(void);
void		menu_helper(void);

#endif
