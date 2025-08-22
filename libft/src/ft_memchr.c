/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:13:28 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:45 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

// int main(void)
// {
//     char str[] = "Hola, mundo!";
//     char c = 'm';
//     size_t n = 15;

//     char *result = ft_memchr(str, c, n);

//     if (result)
//printf
//("El carácter '%c' se encuentra en la posición: %ld\n", c, result - str);
//     else
//         printf("El carácter '%c' no se encuentra en la cadena.\n", c);

//     return 0;
// }
