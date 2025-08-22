/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:03 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:53 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*temp;

	temp = (unsigned char *)ptr;
	while (num--)
		*temp++ = (unsigned char)value;
	return (ptr);
}

// int main(void)
// {
//     char str[50] = "Hola, Mundo! Este es un ejemplo de ft_memset.";

//     printf("Antes de ft_memset: %s\n", str);

//     // Llenamos los primeros 5 caracteres de 'str' con el valor 'X'
//     ft_memset(str, 'X', 5);

//     printf("Después de ft_memset: %s\n", str);

//     return 0;
// }
