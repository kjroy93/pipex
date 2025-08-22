/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:24 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:41 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (1)
	{
		if (*s == (char)c)
			last = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (last);
}

// int main()
// {
//     const char *str = "Hola, ¿cómo estás? Hola de nuevo!";
//     int c = 'o';

//     char *result = ft_strrchr(str, c);

//     if (result)
//         printf("La última ocurrencia de '%c' está en: %s\n", c, result);
//     else
//         printf("El carácter '%c' no se encuentra en la cadena.\n", c);

//     return 0;
// }
