/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:13:57 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:49:51 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}

// int main(void)
// {
// 	char buffer1[20] = "1234567890";
// 	char buffer2[20] = "1234567890";

// 	printf("Antes de ft_memmove:\n");
// 	printf("buffer1: %s\n", buffer1);

// 	ft_memmove(buffer1 + 5, buffer1, 5);
// 	printf("\nDespués de ft_memmove (sin solapamiento):\n");
// 	printf("buffer1: %s\n", buffer1);

// 	ft_memmove(buffer2, buffer2 + 2, 7);
// 	printf("\nDespués de ft_memmove (con solapamiento):\n");
// 	printf("buffer2: %s\n", buffer2);

// 	return 0;
// }
