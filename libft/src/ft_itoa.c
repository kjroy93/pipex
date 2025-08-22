/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:29 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:56 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_count(long n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	count;
	long	nb;

	nb = (long)n;
	count = number_count(nb);
	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--count] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// int main(void)
// {
// 	int numeros[] = {-123, 0, 456, 7890, -2147483648};
// 	size_t i = 0;
// 	char *resultado;

// 	printf("Prueba de ft_itoa:\n");

// 	while (i < sizeof(numeros) / sizeof(numeros[0]))
// 	{
// 		int n = numeros[i];
// 		resultado = ft_itoa(n);
// 		if (resultado)
// 		{
// 			printf("ft_itoa(%d) = %s\n", n, resultado);
// 			free(resultado);
// 		}
// 		else
// 		{
// 			printf("Error al convertir %d\n", n);
// 		}
// 		i++;
// 	}

// 	return 0;
// }
