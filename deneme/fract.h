#ifndef FRACT_H
#define FRACT_H


# include <stdio.h> //DEBUGG
# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include "X11/keysym.h"
# include "X11/X.h"
#include "../libft/libft.h"
#define WIDHT 800
#define HEIGHT 600
#define WHITE 0xFFFFFF


typedef struct s_range
{
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
	
}	t_range;

typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     line;
    int     endian;
}   t_img;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

typedef struct s_fractal
{
    char    *name;
    void    *mlx;
    void    *win;
    t_img   img;
	int     *palette;
    double  escape_val;
    int     iterations_def;
    double  shift_x;
    double  shift_y;
    double  zoom;

    double  julia_x;
    double  julia_y;

    // int     mutex_val;      // exp değerlerinin render sonunda uygulanması için
    // double  exp_sht_x;      // geçici shift x
    // double  exp_sht_y;      // geçici shift y
    // double  exp_zoom;       // geçici zoom
    // int     exp_def;        // geçici iteration değişikliği
}   t_fractal;

//MAİN

//MATH
double 		map(double unscaled_num, t_range range);
t_complex 	square_complex(t_complex z);
t_complex 	sum_complex(t_complex a, t_complex b);

//UTILS
double		ft_atodbl(const char *nptr);
void		malloc_error(void);
int			ft_isvalid_double(const char *s);
void		ft_err_man(void);

//WIN_SIG
int			close_sig(t_fractal *data);
int	esc_input(int key, t_fractal *data);
int	mouse_sig(int button, int x, int y, t_fractal *data);
void	win_init(t_fractal *data);
int render_slice(t_fractal *data);
int create_rgb(int r, int g, int b);
int	*create_pallette(int max_iter);
void	render(t_fractal *data);
// int render_slice(t_fractal *data);

#endif
