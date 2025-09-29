/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pater_son_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:06:08 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:15:01 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	fork_error(t_pipex *data)
{
	ft_putstr_fd("fork: Resource not available.\n", 2);
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
}

static void	init_pater(t_pipex *data, t_cmd **cmd, int *fd)
{
	*cmd = data->cmds;
	*fd = data->infile_fd;
	data->pids = malloc((sizeof(pid_t)) * data->n_cmds);
	if (!data->pids)
	{
		perror("pids");
		exit(EXIT_FAILURE);
	}
}

static t_cmd	*next_cmd(t_pipex *data, t_cmd *cmd, int *prev_fd)
{
	if (*prev_fd != data->infile_fd)
		close(*prev_fd);
	if (cmd->next)
	{
		close(data->pipe_fd[1]);
		*prev_fd = data->pipe_fd[0];
		return (cmd->next);
	}
	if (cmd != data->cmds)
		close(data->pipe_fd[0]);
	return (NULL);
}

static void	childs_bonus(t_pipex *data, t_cmd *cmd, int *fd_in)
{
	if (cmd == data->cmds)
		first_child_bonus(data, cmd);
	else if (cmd->next == NULL)
		last_child_bonus(data, fd_in);
	else
		mid_child_bonus(data, fd_in);
	execute(cmd, data);
}

int	pater_familias_bonus(t_pipex *data)
{
	t_cmd	*cmd;
	pid_t	pid;
	int		prev_fd;
	int		i;

	init_pater(data, &cmd, &prev_fd);
	i = 0;
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(data->pipe_fd) == -1)
				return (perror("pipe"), 1);
		}
		pid = fork();
		if (pid == -1)
			return ((fork_error(data)), 1);
		if (pid == 0)
			childs_bonus(data, cmd, &prev_fd);
		else
			data->pids[i++] = pid;
		cmd = next_cmd(data, cmd, &prev_fd);
	}
	return (special_wait(data->pids, i));
}
