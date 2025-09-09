/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:00:27 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/09 18:57:41 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pater(t_pipex *data, t_cmd **cmd, int *fd)
{
	*cmd = data->cmds;
	*fd = data->infile_fd;
	data->pids = malloc((sizeof(pid_t)) * data->n_cmds);
	if (!data->pids)
		perror_exit("malloc data->pids");
}

static void	execute(t_cmd *cmd, t_pipex *data, char **envp)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
		return ;
	path = define_path(cmd->argv[0], envp);
	if (!path)
		perror_free("command not found", data, path);
	execve(path, cmd->argv, envp);
	perror_free("execve", data, path);
}

static t_cmd	*next_cmd(t_pipex *data, t_cmd *cmd, int *prev_fd, int fd[2])
{
	if (*prev_fd != data->infile_fd)
		close(*prev_fd);
	if (cmd->next)
	{
		close(fd[1]);
		*prev_fd = fd[0];
		return (cmd->next);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		return (NULL);
	}
	*prev_fd = fd[0];
	return (cmd->next);
}

static void	childs_bonus(t_pipex *data, t_cmd *cmd, int fd[2], int *fd_in)
{
	if (cmd == data->cmds)
		redirect_infile(data->infile_fd);
	else
		redirect_pipe_in(*fd_in);
	if (cmd->next)
		redirect_pipe_out(fd[1]);
	else
		redirect_outfile(data->outfile_fd);
	close(fd[0]);
	close(fd[1]);
	execute(cmd, data, data->envp);
}

int	pater_familias_bonus(t_pipex *data)
{
	t_cmd	*cmd;
	pid_t	pid;
	int		fd[2];
	int		prev_fd;
	int		i;

	init_pater(data, &cmd, &prev_fd);
	i = 0;
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(fd) == -1)
				perror_exit("pipe");
		}
		pid = fork();
		if (pid == -1)
			perror_exit("pid");
		if (pid == 0)
			childs_bonus(data, cmd, fd, &prev_fd);
		else
			data->pids[i++] = pid;
		cmd = next_cmd(data, cmd, &prev_fd, fd);
	}
	return (special_wait(data->pids, i));
}
