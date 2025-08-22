/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:50 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:46 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (((unsigned char)c >= '0' && (unsigned char)c <= '9')
		|| ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
		|| ((unsigned char)c >= 'a' && (unsigned char)c <= 'z'));
}

// int main(void)
// {
// 	char caracteres[] = {'a', 'Z', '3', '%', ' ', '\n', '0'};
// 	size_t i = 0;

// 	printf("Prueba de ft_isalnum:\n");

// 	while (i < sizeof(caracteres))
// 	{
// 		char c = caracteres[i];
// 		if (ft_isalnum(c))
// 			printf("'%c' es alfanumérico.\n", c);
// 		else
// 			printf("'%c' NO es alfanumérico.\n", c);
// 		i++;
// 	}

// 	return 0;
// }
