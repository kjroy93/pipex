/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:50 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:30 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

// int main()
// {
//     char src[] = "Hola, Mundo!";
//     char dst[20];
//     size_t size = 10;

//     printf("Antes de ft_strlcpy:\n");
//     printf("src: %s\n", src);
//     printf("dst: %s\n", dst);

//     size_t result = ft_strlcpy(dst, src, size);

//     printf("\nDespués de ft_strlcpy:\n");
//     printf("dst: %s\n", dst);
//     printf("longitud de src: %zu\n", result);

//     return 0;
// }
