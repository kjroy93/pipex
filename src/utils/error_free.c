/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:05:56 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/26 17:28:25 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	error_message(t_cmd *cmd, char*path)
{
	if (!path)
	{
		if (cmd && cmd->argv && cmd->argv[0])
			ft_putstr_fd(cmd->argv[0], 2);
		ft_putstr_fd(" :command not found", 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	else
	{
		perror("execve");
		return (2);
	}
}

void	perror_free(t_pipex *data, t_cmd *cmd, char *path)
{
	int	code;

	code = error_message(cmd, path);
	if (data)
		free_pipex(data);
	if (path)
		free(path);
	if (code == 1)
		exit(127);
	else if (code == 2)
		exit(126);
	else
		exit(EXIT_FAILURE);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_pipex(t_pipex *data)
{
	if (!data)
		return ;
	if (data->cmds)
		cmd_free(&data->cmds);
	if (data->pids)
		free(data->pids);
	if (data->infile_fd > 2)
		close(data->infile_fd);
	if (data->outfile_fd > 2)
		close(data->outfile_fd);
	if (data->pipe_fd[0] > 2)
		close(data->pipe_fd[0]);
	if (data->pipe_fd[1] > 2)
		close(data->pipe_fd[1]);
	if (data->heredoc)
		get_next_line(-1);
	free(data);
}
