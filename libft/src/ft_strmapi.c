/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:04 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:34 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char to_uppercase(unsigned int i, char c)
// {
//     if (c >= 'a' && c <= 'z')
//         return c - 32;
//     return c;
// }

// int main()
// {
//     const char *str = "hola, mundo!";
//     char *result;

//     result = ft_strmapi(str, to_uppercase);

//     if (result)
//     {
//         printf("Resultado de ft_strmapi: %s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Error en la asignación de memoria.\n");
//     }

//     return 0;
// }
