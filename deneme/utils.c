/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:30:08 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/28 02:32:19 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void	malloc_error(void)
{
	perror("Problems with Malloc");
	exit(EXIT_FAILURE);
}


int	ft_isvalid_double(const char *s)
{
	int	dot_count;

	dot_count = 0;
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		else if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

void	ft_err_man(void)
{
	ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

double	ft_atodbl(const char *nptr)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0.0;
	fractional_part = 0.0;
	sign = 1;
	pow = 1.0;
	while (*nptr && (*nptr == ' ' || (9 <= *nptr && *nptr <= 13)))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr != '.' && *nptr)
		integer_part = integer_part * 10 + (*nptr++ - '0');
	if ('.' == *nptr)
		++nptr;
	while (*nptr && ft_isdigit(*nptr))
	{
		fractional_part = fractional_part * 10 + (*nptr++ - '0');
		pow *= 10;
	}
	return (sign * (integer_part + fractional_part / pow));
}
