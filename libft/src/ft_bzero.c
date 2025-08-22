/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:26 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:41 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}

// int main(void)
// {
// 	char buffer[10] = "123456789";
// 	int i = 0;

// 	printf("Antes de ft_bzero: %s\n", buffer);

// 	ft_bzero(buffer, 5);

// 	printf("Después de ft_bzero:\n");
// 	while (i < 10)
// 	{
// 		printf("buffer[%d] = 0x%02x\n", i, (unsigned char)buffer[i]);
// 		i++;
// 	}

// 	return 0;
// }
