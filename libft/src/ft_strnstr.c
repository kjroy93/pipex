/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:19 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:38 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && (i + j) < len && needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
//     const char *haystack = "Este es un ejemplo de búsqueda.";
//     const char *needle1 = "ejemplo";
//     const char *needle2 = "búsqueda";
//     const char *needle3 = "no existe";
//     size_t len = 20;

//     char *result1 = ft_strnstr(haystack, needle1, len);
//     if (result1)
//         printf("Encontrado \"%s\" en: \"%s\"\n", needle1, result1);
//     else
//         printf("No se encontró \"%s\".\n", needle1);
//     char *result2 = ft_strnstr(haystack, needle2, len);
//     if (result2)
//         printf("Encontrado \"%s\" en: \"%s\"\n", needle2, result2);
//     else
//         printf("No se encontró \"%s\".\n", needle2);
//     char *result3 = ft_strnstr(haystack, needle3, len);
//     if (result3)
//         printf("Encontrado \"%s\" en: \"%s\"\n", needle3, result3);
//     else
//         printf("No se encontró \"%s\".\n", needle3);

//     return 0;
// }
