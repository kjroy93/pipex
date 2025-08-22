/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:00 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:48 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int main(void)
// {
// 	char caracteres[] = {'A', 'z', 'M', '1', '*', ' ', '\n'};
// 	size_t i = 0;

// 	printf("Prueba de ft_isalpha:\n");

// 	while (i < sizeof(caracteres))
// 	{
// 		char c = caracteres[i];
// 		if (ft_isalpha(c))
// 			printf("'%c' es una letra.\n", c);
// 		else
// 			printf("'%c' NO es una letra.\n", c);
// 		i++;
// 	}

// 	return 0;
// }
