/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydinler <ydinler@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:23:57 by ydinler           #+#    #+#             */
/*   Updated: 2025/09/26 01:35:39 by ydinler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
