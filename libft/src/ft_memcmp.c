/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:13:49 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:47 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (const unsigned char *)ptr1;
	ptr_2 = (const unsigned char *)ptr2;
	while (n--)
	{
		if (*ptr_1 != *ptr_2)
			return ((int)(*ptr_1 - *ptr_2));
		ptr_1++;
		ptr_2++;
	}
	return (0);
}

// int main(void)
// {
//     char str1[] = "Hola, Mundo!";
//     char str2[] = "Hola, Mundo!";
//     char str3[] = "Hola, mundo!";
//     char str4[] = "Hola, Mundo!";
//     int result1 = ft_memcmp(str1, str2, 15);
//     if (result1 == 0)
//         printf("str1 y str2 son iguales.\n");
//     else
//         printf("str1 y str2 son diferentes. Resultado: %d\n", result1);
//     int result2 = ft_memcmp(str1, str3, 15);
//     if (result2 == 0)
//         printf("str1 y str3 son iguales.\n");
//     else
//         printf("str1 y str3 son diferentes. Resultado: %d\n", result2);
//     int result3 = ft_memcmp(str1, str4, 15);
//     if (result3 == 0)
//         printf("str1 y str4 son iguales.\n");
//     else
//         printf("str1 y str4 son diferentes. Resultado: %d\n", result3);

//     return 0;
// }
