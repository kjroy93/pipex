/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:31 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:47 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_bitmask(unsigned char *bitmask, const char *to_delete)
{
	int	c;

	c = 0;
	ft_bzero(bitmask, 256);
	while (to_delete[c])
	{
		bitmask[(unsigned char)to_delete[c]] = 1;
		c++;
	}
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned char	bitmask[256];
	size_t			start;
	size_t			end;
	char			*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	get_bitmask(bitmask, set);
	start = 0;
	while (s1[start] && bitmask[(unsigned char)s1[start]])
		start++;
	end = ft_strlen(s1);
	while (end > start && bitmask[(unsigned char)s1[end - 1]])
		end--;
	trimmed_str = malloc(end - start + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
	return (trimmed_str);
}

// int main()
// {
//     const char *str = "  \t  Hola, Mundo!   \n\t  ";
//     const char *set = " \t\n";

//     char *trimmed_str = ft_strtrim(str, set);

//     if (trimmed_str)
//     {
//         printf("Cadena original: '%s'\n", str);
//         printf("Cadena recortada: '%s'\n", trimmed_str);
//         free(trimmed_str);
//     }
//     else
//     {
//         printf("Error al recortar la cadena.\n");
//     }

//     return 0;
// }
