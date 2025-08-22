/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:31:07 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:06 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *string)
{
	size_t	i;
	int		ret;

	if (string == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (string[i] != '\0')
	{
		ret = write(1, &string[i], 1);
		if (ret == -1)
			return (-1);
		i++;
	}
	return (i);
}
