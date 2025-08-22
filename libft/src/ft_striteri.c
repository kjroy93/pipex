/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:38 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:23 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// void print_char_with_index(unsigned int index, char *c)
// {
//     printf("Índice %u: Carácter %c\n", index, *c);
// }

// int main()
// {
//     char str[] = "Hola Mundo!";

//     ft_striteri(str, print_char_with_index);

//     printf("Cadena modificada: %s\n", str);

//     return 0;
// }
