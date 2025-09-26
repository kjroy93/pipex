/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:06:01 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/26 16:06:46 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*prepare_node(char *cmd_str, int i)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->argv = split_with_quotes(cmd_str);
	node->index = i;
	node->next = NULL;
	return (node);
}

void	cmd_add_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	cmd_free(t_cmd **cmds)
{
	t_cmd	*tmp;
	t_cmd	*cur;
	int		i;

	if (!cmds || !*cmds)
		return ;
	cur = *cmds;
	while (cur)
	{
		tmp = cur->next;
		if (cur->argv)
		{
			i = 0;
			while (cur->argv[i])
			{
				free(cur->argv[i]);
				i++;
			}
			free(cur->argv);
		}
		free(cur);
		cur = tmp;
	}
	*cmds = NULL;
}

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

void	execute(t_cmd *cmd, t_pipex *data, char **envp)
{
	char	*path;

	if (!cmd || !cmd->argv || !cmd->argv[0])
	{
		cmd_free(&data->cmds);
		free_pipex(data);
		exit(127);
	}
	path = define_path(cmd->argv[0], envp);
	if (!path)
		perror_free(data, cmd, path);
	if (execve(path, cmd->argv, envp) == -1)
		perror_free(data, cmd, path);
}
