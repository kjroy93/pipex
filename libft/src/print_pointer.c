/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:31:02 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:03 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpointer(unsigned long ptr)
{
	int	count;
	int	ret;

	count = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	ret = write(1, "0x", 2);
	count += ret;
	ret = ft_puthex_ulong(ptr, 0);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
