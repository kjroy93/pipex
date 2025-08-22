/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:58 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:32 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t		len;
	const char	*ptr;

	ptr = s;
	len = 0;
	while (*ptr)
	{
		len++;
		ptr++;
	}
	return (len);
}

// int main()
// {
//     const char *str1 = "Hola, Mundo!";
//     const char *str2 = "42 Cursus";

//     size_t len1 = ft_strlen(str1);
//     size_t len2 = ft_strlen(str2);

//     printf("Longitud de la cadena 1: \"%s\" es %zu\n", str1, len1);
//     printf("Longitud de la cadena 2: \"%s\" es %zu\n", str2, len2);

//     return 0;
// }
