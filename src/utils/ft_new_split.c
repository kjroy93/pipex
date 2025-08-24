/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:17:07 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/24 15:22:15 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	int	is_space(char c)
{
	return (c <= 32);
}

static void	skip_space(const char *s, int *i)
{
	while (s[*i] && is_space(s[*i]))
		(*i)++;
}

char **split_with_quiotes(const char *s)
{
	char	**argv;
	int		i;
}