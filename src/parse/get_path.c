/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:50:24 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/31 13:46:57 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*is_accesible(char **paths, int *i, char *cmd)
{
	char	*path;
	char	*tmp;

	while (paths[*i])
	{
		tmp = ft_strjoin(paths[*i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		(*i)++;
	}
	return (NULL);
}

char	*define_path(char *cmd, char **envp)
{
	char	*full_path;
	char	**paths;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	full_path = is_accesible(paths, &i, cmd);
	free_matrix(paths);
	return (full_path);
}
