/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:44 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:55 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

// int main(void)
// {
//     char minus = 'g';
//     char mayus = ft_toupper(minus);

//     printf("Original: %c\n", minus);
//     printf("Convertido a mayúscula: %c\n", mayus);

//     return 0;
// }
