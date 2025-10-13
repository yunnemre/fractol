/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:26:38 by ydinler           #+#    #+#             */
/*   Updated: 2025/10/13 19:32:05 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //DEBUGG
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"
# include "libft.h"
# include <math.h>
# define WIDHT	800
# define HEIGHT	800

# define BLACK       0x000000  // Siyah
# define WHITE       0xFFFFFF  // Beyaz
# define RED         0xFF0000  // Kırmızı
# define GREEN       0x00FF00  // Yeşil
# define BLUE        0x0000FF  // Mavi
# define YELLOW      0xFFFF00  // Sarı
# define CYAN        0x00FFFF  // Camgöbeği
# define MAGENTA     0xFF00FF  // Eflatun
# define GRAY        0x808080  // Gri
# define ORANGE      0xFFA500  // Turuncu
# define PURPLE      0x800080  // Mor
# define BROWN       0x8B4513  // Kahverengi
# define PINK        0xFFC0CB  // Pembe
# define LIGHT_GRAY  0xD3D3D3  // Açık gri
# define DARK_GRAY   0x404040  // Koyu gri
# define NAVY        0x000080  // Lacivert
# define TEAL        0x008080  // Camgöbeği koyu
# define OLIVE       0x808000  // Zeytin yeşili
# define GOLD        0xFFD700  // Altın sarısı
# define SILVER      0xC0C0C0  // Gümüş

# define PALETE_SIZE 2048

typedef struct s_rgb
{
	double		t;
	int			r;
	int			g;
	int			b;
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
int			create_rgb1(t_rgb rgb);
int			create_rgb2(t_rgb rgb);
int			create_rgb3(t_rgb rgb);

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
int			jul_motion_sig(int x, int y, t_fractal *jul);
int			jul_expose(t_fractal *jul);

//helper.c
void		malloc_error(void);
void		start_helper(void);
void		menu_helper(void);

#endif

// burayı duzenlemyi unutma dosyarar gore fonksiyonalrı 
//sırala gerkeiz fonksiyonalrı ve defineları kaldır
// typedef struct s_iter_result
// {
//     int iterations;
//     t_complex z_last;
// } t_iter_result;
// int *load_palette_from_file(const char *filename, int *size);
// t_complex	sum_complex(t_complex z1, t_complex z2);
// t_complex	square_complex(t_complex z);