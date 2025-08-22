/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:31:11 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:09 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putunsigned_recursive(unsigned int n)
{
	char	digit;
	int		ret;
	int		count;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunsigned_recursive(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	digit = (n % 10) + '0';
	if (write(1, &digit, 1) == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_putunsigned_recursive(n));
}
