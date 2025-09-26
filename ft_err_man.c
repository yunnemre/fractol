/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_man.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 15:30:19 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 16:00:49 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"

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
