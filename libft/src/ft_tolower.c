/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:15:40 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:50:52 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}

// int main(void)
// {
//     char mayus = 'H';
//     char minus = ft_tolower(mayus);

//     printf("Original: %c\n", mayus);
//     printf("Convertido a minúscula: %c\n", minus);

//     return 0;
// }
