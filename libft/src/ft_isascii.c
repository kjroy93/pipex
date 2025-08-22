/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:08 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:50 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int main(void)
// {
// 	int valores[] = {-1, 0, 65, 127, 128, 255};
// 	size_t i = 0;

// 	printf("Prueba de ft_isascii:\n");

// 	while (i < sizeof(valores) / sizeof(valores[0]))
// 	{
// 		int c = valores[i];
// 		if (ft_isascii(c))
// 			printf("ft_isascii(%d) -> TRUE (es ASCII)\n", c);
// 		else
// 			printf("ft_isascii(%d) -> FALSE (NO es ASCII)\n", c);
// 		i++;
// 	}

// 	return 0;
// }
