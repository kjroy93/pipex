/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:14:24 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/18 20:33:35 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_and_copy(const char *s, char **dest, int len)
{
	int	j;

	j = 0;
	*dest = malloc(len + 1);
	if (!*dest)
		return (0);
	while (j < len)
	{
		(*dest)[j] = s[j];
		j++;
	}
	(*dest)[len] = '\0';
	return (1);
}

static void	free_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static int	split_words(const char *s, char c, char **result)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			if (!alloc_and_copy(s, &result[i], len))
			{
				free_result(result, i - 1);
				return (0);
			}
			s += len;
			i++;
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		words;
	char	**result;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!split_words(s, c, result))
		return (NULL);
	return (result);
}

// #include "libft.h"

// int main(void)
// {
// 	const char *texto = "Hola,,esto,es,una,prueba,de,split";
// 	char delimitador = ',';
// 	char **resultado;
// 	int i = 0;

// 	resultado = ft_split(texto, delimitador);
// 	if (!resultado)
// 	{
// 		printf("Error: ft_split devolvió NULL.\n");
// 		return (1);
// 	}

// 	printf("Resultado de ft_split:\n");
// 	while (resultado[i])
// 	{
// 		printf("Palabra %d: %s\n", i, resultado[i]);
// 		free(resultado[i]);
// 		i++;
// 	}
// 	free(resultado);

// 	return 0;
// }
