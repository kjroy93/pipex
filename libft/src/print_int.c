/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:30:57 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:31:01 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_recursive(unsigned long n)
{
	char	digit;
	int		ret;
	int		count;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putnbr_recursive(n / 10);
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

int	ft_putnbr(int n)
{
	int				count;
	int				ret;
	unsigned long	unb;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		unb = (unsigned long)(-(long)n);
	}
	else
		unb = (unsigned long)n;
	ret = ft_putnbr_recursive(unb);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
