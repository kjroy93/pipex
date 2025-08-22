/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:11 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:05 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	*temp;

	if (!s)
		return ;
	temp = s;
	while (*temp)
	{
		write(fd, temp, 1);
		temp++;
	}
	write(fd, "\n", 1);
}
