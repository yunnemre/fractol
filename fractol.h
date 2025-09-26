/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:26:38 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 15:56:21 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h> //DEBUGG
# include <stdlib.h>
# include <unistd.h>
# include <math.h> // kulanılmadı
# include "minilibx-linux/mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"

# define WIDHT	800
# define HEIGHT	800
# define ERROR_MESSAGE "Please enter \n\t\" ./fractol mandelbrot\" or \n\t\" ./fractol julia  <value_reel> <value_complex> \" "

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

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

// typedef struct s_range
// {
// 	double	new_min;
// 	double	new_max;
// 	double	old_min;
// 	double	old_max;
	
// }	t_range;

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
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_val;
	int		iterations_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

int			close_sig(t_fractal *data);
int			esc_input(int key, t_fractal *data);
int			mouse_sig(int button, int x, int y, t_fractal *data);
int			motion_sig(int x, int y, t_fractal *data);

void		render(t_fractal *data);
void		fractal_init(t_fractal *data);

//double	map(double unscaled_num, t_range range);
double		map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

void		ft_err_man(void);
int			ft_isvalid_double(const char *s);

#endif