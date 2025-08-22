/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:14 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:52 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int main(void)
// {
// 	int caracteres[] = {'0', '5', '9', 'a', 'Z', ' ', '-', '8'};
// 	size_t i = 0;

// 	printf("Prueba de ft_isdigit:\n");

// 	while (i < sizeof(caracteres) / sizeof(caracteres[0]))
// 	{
// 		int c = caracteres[i];
// 		if (ft_isdigit(c))
// 			printf("ft_isdigit('%c') -> TRUE (es un dígito)\n", c);
// 		else
// 			printf("ft_isdigit('%c') -> FALSE (NO es un dígito)\n", c);
// 		i++;
// 	}

// 	return 0;
// }
