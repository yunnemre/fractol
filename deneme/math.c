/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:30:32 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/28 02:30:43 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double map(double unscaled_num, t_range range)
{
   return ((range.new_max - range.new_min) * (unscaled_num - range.old_min)
		/ (range.old_max - range.old_min) + range.new_min);
}

t_complex square_complex(t_complex z)
{
    t_complex res;
    res.x = z.x * z.x - z.y * z.y;
    res.y = 2 * z.x * z.y;
    return (res);
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex res;
    res.x = z1.x + z2.x;
    res.y = z1.y + z2.y;
    return (res);
}
