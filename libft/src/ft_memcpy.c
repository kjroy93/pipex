/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:13:53 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:49 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if (n == 0 || dest == src)
		return (dest);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}

// int main(void)
// {
//     char src[] = "Hola, Mundo!";
//     char dest[20];
//     char dest2[20];

//     ft_memcpy(dest, src, 13);
//     memcpy(dest2, src, 13);

//     printf("src: %s\n", src);
//     printf("dest después de ft_memcpy: %s\n", dest);
//     printf("dest2 después de memcpy: %s\n", dest2);

//     return 0;
// }
