/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:17:07 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/27 21:28:05 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_space(char c)
{
	return (c <= 32);
}

static void	skip_spaces(const char *s, int *i)
{
	while (s[*i] && is_space(s[*i]))
		(*i)++;
}

static void	sub_chain(const char *s, char **argv, int *i, int *argc)
{
	char	quote;
	int		start;

	quote = s[*i];
	(*i)++;
	start = *i;
	while (s[*i] && s[*i] != quote)
		(*i)++;
	argv[*argc] = ft_substr(s, (unsigned int)start, (size_t)(*i - start));
	(*argc)++;
	if (s[*i] == quote)
		(*i)++;
}

static void	normal_chain(const char *s, char **argv, int *i, int *argc)
{
	int	start;

	start = *i;
	while (s[*i] && !is_space(s[*i]) && s[*i] != '"' && s[*i] != '\'')
		(*i)++;
	argv[*argc] = ft_substr(s, (unsigned int)start, (size_t)(*i - start));
	(*argc)++;
}

char	**split_with_quotes(const char *s)
{
	char	**argv;
	int		argc;
	int		i;

	if (!s)
		return (NULL);
	argv = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!argv)
		return (NULL);
	i = 0;
	argc = 0;
	while (s[i])
	{
		skip_spaces(s, &i);
		if (!s[i])
			break ;
		if (s[i] == '"' || s[i] == '\'')
			sub_chain(s, argv, &i, &argc);
		else
			normal_chain(s, argv, &i, &argc);
	}
	argv[argc] = NULL;
	return (argv);
}
