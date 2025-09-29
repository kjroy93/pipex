/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:22:53 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:14:40 by kmarrero         ###   ########.fr       */
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

static char	*relative_absolute_path(char *cmd)
{
	if (access(cmd, F_OK) != 0)
		return (NULL);
	if (access(cmd, X_OK) != 0)
		return (ft_strdup(cmd));
	return (ft_strdup(cmd));
}

char	*define_path(char *cmd, char **envp)
{
	char	*full_path;
	char	**paths;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (relative_absolute_path(cmd));
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	full_path = is_accesible(paths, &i, cmd);
	if (!full_path)
	{
		free_matrix(paths);
		ft_printf("command not found: %s\n", cmd);
		return (NULL);
	}
	free_matrix(paths);
	return (full_path);
}

void	get_commands(int argc, char **argv, t_pipex *data)
{
	int		i;
	int		start;
	t_cmd	*new;

	if (data->heredoc)
		start = 3;
	else
		start = 2;
	data->n_cmds = argc - start - 1;
	data->cmds = NULL;
	i = 0;
	while (i < data->n_cmds)
	{
		new = prepare_node(argv[start + i], i);
		if (new)
			cmd_add_back(&data->cmds, new);
		i++;
	}
}
