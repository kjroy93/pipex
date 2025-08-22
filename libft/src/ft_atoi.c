/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:20 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:35 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (INT_MAX);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (INT_MIN);
		i++;
	}
	return ((int)(sign * result));
}

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		printf("Uso: %s <cadena_numérica>\n", argv[0]);
// 		return (1);
// 	}

// 	int resultado = ft_atoi(argv[1]);
// 	printf("Resultado de ft_atoi: %d\n", resultado);

// 	return (EXIT_SUCCESS);
// }
