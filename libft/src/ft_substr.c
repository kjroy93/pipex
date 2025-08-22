/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:36 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:49 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// int main(void)
// {
//     const char *original = "Hola, mundo!";
//     unsigned int start = 6;
//     size_t len = 5;

//     char *sub = ft_substr(original, start, len);

//     if (sub)
//     {
//         printf("Cadena original: \"%s\"\n", original);
//printf("Subcadena
//desde posición %u con longitud %zu: \"%s\"\n", start, len, sub);
//         free(sub);
//     }
//     else
//     {
//         printf("Error al generar la subcadena.\n");
//     }

//     return 0;
// }
