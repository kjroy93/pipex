/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:42 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:25 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		new_string[i++] = s2[j++];
	new_string[i] = '\0';
	return (new_string);
}

// int main()
// {
//     const char *str1 = "Hola, ";
//     const char *str2 = "Mundo!";

//     char *resultado = ft_strjoin(str1, str2);

//     if (resultado == NULL)
//     {
//         printf("Error al concatenar las cadenas\n");
//         return 1;
//     }

//     printf("Cadena concatenada: %s\n", resultado);

//     free(resultado);

//     return 0;
// }
