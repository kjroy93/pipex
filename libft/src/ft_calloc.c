/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:37 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 19:48:44 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

// int main(void)
// {
// 	int	*arr;
// 	size_t	count = 5;
// 	size_t	i = 0;

// 	arr = (int *)ft_calloc(count, sizeof(int));
// 	if (!arr)
// 	{
// 		printf("Error: ft_calloc falló al reservar memoria.\n");
// 		return (1);
// 	}

// 	printf("Contenido del arreglo después de ft_calloc:\n");
// 	while (i < count)
// 	{
// 		printf("arr[%zu] = %d\n", i, arr[i]);
// 		i++;
// 	}

// 	free(arr);
// 	return (0);
// }
