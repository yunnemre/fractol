/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:26:38 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/04 02:06:14 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "/usr/include/X11/keysym.h"

typedef struct s_mlxdata
{
	void	*mlx;
	void	*win;
	//t_img   img;               // aktif image buffer

	//double  zoom;              // zoom katsayısı
    //double  offset_x;          // x ekseni kaydırma
    //double  offset_y;          // y ekseni kaydırma
    //int     max_iter;          // maksimum iterasyon (renk için)
    int     fractal_type;
} t_mlxdata;

int	helper(int no);

#endif