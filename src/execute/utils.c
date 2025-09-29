/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:03:30 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:16:37 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_pipex *data)
{
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd < 0)
	{
		perror(data->infile);
		data->infile_fd = open("/dev/null", O_RDONLY);
		if (data->infile_fd < 0)
			return (perror("open /dev/null"), 1);
	}
	if (!data->heredoc)
		data->outfile_fd = open(data->outfile,
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		data->outfile_fd = open(data->outfile,
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (data->outfile_fd < 0)
	{
		perror(data->outfile);
		close(data->infile_fd);
		return (1);
	}
	return (0);
}

void	execute(t_cmd *cmd, t_pipex *data)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
	{
		cmd_free(&data->cmds);
		free_pipex(data);
		exit(127);
	}
	path = define_path(cmd->argv[0], data->envp);
	if (!path)
		perror_free(data, cmd, NULL);
	if (access(path, X_OK) != 0)
		perror_free(data, cmd, path);
	if (execve(path, cmd->argv, data->envp) == -1)
		perror_free(data, cmd, path);
}
