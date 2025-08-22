/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:30:49 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:30:58 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number(unsigned long n, char *hex, int uppercase)
{
	int		remainer;
	int		i;

	if (uppercase == 0)
		uppercase = 'a';
	else
		uppercase = 'A';
	i = 0;
	while (n > 0)
	{
		remainer = n % 16;
		if (remainer < 10)
			hex[i] = remainer + '0';
		else
			hex[i] = remainer - 10 + uppercase;
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_puthex_uint(unsigned int n, int uppercase)
{
	char	hex[9];
	char	temp;
	int		len;
	int		i;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	len = get_number(n, hex, uppercase);
	i = 0;
	while (i < len / 2)
	{
		temp = hex[i];
		hex[i] = hex[len - i - 1];
		hex[len - i - 1] = temp;
		i++;
	}
	count = write(1, hex, len);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_puthex_ulong(unsigned long n, int uppercase)
{
	char	hex[17];
	char	temp;
	int		len;
	int		i;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	len = get_number(n, hex, uppercase);
	i = 0;
	while (i < len / 2)
	{
		temp = hex[i];
		hex[i] = hex[len - i - 1];
		hex[len - i - 1] = temp;
		i++;
	}
	count = write(1, hex, len);
	if (count == -1)
		return (-1);
	return (count);
}
