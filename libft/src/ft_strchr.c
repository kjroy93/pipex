/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:29 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:19 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		i++;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// int main()
// {
//     const char *str = "Hola Mundo!";
//     char ch = 'M';

//     // Usar ft_strchr para encontrar el primer 'M' en la cadena
//     char *result = ft_strchr(str, ch);

//     if (result != NULL)
//printf("Se encontró el carácter 
//'%c' en la posición: %ld\n", ch, result - str);
//     else
//         printf("El carácter '%c' no se encontró en la cadena.\n", ch);

//     // Buscar un carácter que no existe en la cadena
//     ch = 'z';
//     result = ft_strchr(str, ch);

//     if (result != NULL)
//printf("Se encontró el carácter 
//'%c' en la posición: %ld\n", ch, result - str);
//     else
//         printf("El carácter '%c' no se encontró en la cadena.\n", ch);

//     // Buscar el carácter nulo '\0'
//     ch = '\0';
//     result = ft_strchr(str, ch);

//     if (result != NULL)
//printf("Se encontró el carácter nulo en la posición: %ld\n", result - str);
//     else
//         printf("El carácter nulo no se encontró en la cadena.\n");

//     return 0;
// }
