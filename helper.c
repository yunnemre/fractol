/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:17:27 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/04 02:06:05 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"

int	helper(int no)
{
	if (no == 1)
	{
		ft_printf("Yanlis Kullnım "
		 	"\n ./fractol mandelbrot  or ./fractol julia \n"
				"(if you want adres of to julia boyle de kualanbişirln ./fractol julia 2.5 1.2)");
		exit(1);
	}
	
}