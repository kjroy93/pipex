/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:14 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:36 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

// int main()
// {
//     const char *str1 = "Hola, Mundo!";
//     const char *str2 = "Hola, Mundo!";
//     const char *str3 = "Hola, Mundo!123";
//     const char *str4 = "Hola, Mundo!";

//     size_t n = 5;

//     int result1 = ft_strncmp(str1, str2, n);
//printf("Comparando \"%s\" y \"%s\" con n=%zu: %d\n", str1, str2, n, result1);

//     int result2 = ft_strncmp(str1, str3, n);
//printf("Comparando \"%s\" y \"%s\" con n=%zu: %d\n", str1, str3, n, result2);

//     int result3 = ft_strncmp(str1, str4, n);
//printf("Comparando \"%s\" y \"%s\" con n=%zu: %d\n", str1, str4, n, result3);

//     return 0;
// }
