/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:49:55 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 14:37:58 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;
	
	if (NULL == s || fd < 0)
		return ;		
	if (*s != '\0')
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	while ((*p1 && n > 0) || (*p2 && n > 0))
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		p1++;
		p2++;
		n--;
	}
	return (0);
}




// int	handle_input(int key, t_mlxdata *data)
// {
// 	if (key == XK_Escape)
// 	{
// 		ft_printf("The %d key (ESC) has been pressed \n", key);
// 		mlx_destroy_window(data->mlx, data->win);
// 		mlx_destroy_display(data->mlx);
// 		free(data->mlx);
// 		exit(1);
// 	}
// 	ft_printf("The %d key has been pressed\n", key);
// 	return (0);
// }

// int	close_sig(t_mlxdata *data)
// {
// 	mlx_destroy_window(data->mlx, data->win);
// 	mlx_destroy_display(data->mlx);
// 	free(data->mlx);
// 	exit(0);
// }
// typedef struct s_complex
// {
// 	double real;
	
// 	double i;
// } t_complex;



// t_complex z;
// 	t_complex c;
// 	double tmp_real;

// 	z.real = 0;
// 	z.i =0;

// 	c.real = 0.25;
// 	c.i = 0.4;
// 	for (int i = 0; i < 42; i++)
// 	{
// 		tmp_real = (z.real *z.real) - (z.i * z.i);
// 		z.i = 2 * z.real * z.i;
// 		z.real = tmp_real;

// 		z.real += c.real;
// 		z.i += c.i;
// 		printf("iteartion number ->%d , real %f , imaginory %f \n",i , z.real,z.i);
// 	}

// void ft_check_arg(int argc, char **argv, t_mlxdata *data)
// {
// 	if (argc == 2)
// 	{
// 		if (ft_strncmp(argv[1] ,"mandelbrot", 9))
// 		{
// 			data->fractal_type = 1;
// 			return ;
// 		}
// 		if (ft_strncmp(argv[1] ,"julia", 5))
// 		{
// 			data->fractal_type = 2;
// 			return ;
// 		}
// 	}
// 	else if (argc == 4)
// 	{
// 		if (!ft_strncmp(argv[1] ,"julia", 5))
// 			return (helper(1));
// 		data->fractal_type = 2;
		
// 	}
	
// }

// data.mlx = mlx_init();
// 		if (data.mlx == NULL)
// 			return (1);
// 		data.win = mlx_new_window(data.mlx, 800, 800, "Fractol");
// 		if (data.win == NULL)
// 		{
// 			mlx_destroy_display(data.mlx);
// 			free(data.mlx);
// 			return (1);
// 		}
// 		mlx_key_hook(data.win,handle_input, &data);
// 		mlx_hook(data.win, 17, 0, close_sig, &data);