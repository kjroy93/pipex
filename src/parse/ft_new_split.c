/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:44 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/22 19:22:46 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	skip_spaces(const char *s, int *i)
{
	while (s[*i] && s[*i] <= 32)
		(*i)++;
}

static void	sub_chain(const char *s, char **argv, int *i, int *argc)
{
	char	quote;
	int		start;

	quote = s[*i];
	if (s[*i] == quote)
		(*i)++;
	start = (*i);
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
	while (s[*i] && !(s[*i] <= 32) && s[*i] != '"' && s[*i] != '\'')
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
