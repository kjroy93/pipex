/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:46 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:27 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	k;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest] != '\0')
		len_dest++;
	while (src[len_src] != '\0')
		len_src++;
	k = 0;
	if (len_dest >= size)
		return (len_src + size);
	while (k < (size - len_dest - 1) && src[k] != '\0')
	{
		dest[len_dest + k] = src[k];
		k++;
	}
	dest[len_dest + k] = '\0';
	return (len_dest + len_src);
}

// int main()
// {
//     char dest[50] = "Hola, ";
//     const char *src = "Mundo!";
//     size_t size = 20;

//     printf("Antes de ft_strlcat:\n");
//     printf("dest: %s\n", dest);
//     printf("src: %s\n", src);

//     size_t result = ft_strlcat(dest, src, size);

//     printf("\nDespués de ft_strlcat:\n");
//     printf("dest: %s\n", dest);
//     printf("longitud resultante: %zu\n", result);

//     return 0;
// }
