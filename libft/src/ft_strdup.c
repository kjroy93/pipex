/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:33 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:21 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*copy;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

// int main()
// {
//     const char *original = "¡Hola, Mundo!";

//     char *duplicada = ft_strdup(original);

//     if (duplicada == NULL)
//     {
//         printf("Error al duplicar la cadena\n");
//         return (1);
//     }

//     printf("Cadena original: %s\n", original);
//     printf("Cadena duplicada: %s\n", duplicada);

//     free(duplicada);

//     return 0;
// }
