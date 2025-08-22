/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:20 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:54 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int main(void)
// {
// 	int caracteres[] = {31, 32, 50, 65, 126, 127};
// 	size_t i = 0;

// 	printf("Prueba de ft_isprint:\n");

// 	while (i < sizeof(caracteres) / sizeof(caracteres[0]))
// 	{
// 		int c = caracteres[i];
// 		if (ft_isprint(c))
// 			printf("ft_isprint(%d) -> TRUE (es un carácter imprimible)\n", c);
// 		else
// printf("ft_isprint(%d) -> FALSE (NO es un carácter imprimible)\n", c);
// 		i++;
// 	}

// 	return 0;
// }
