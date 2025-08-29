/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:57:10 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/29 23:22:43 by kjroy93          ###   ########.fr       */
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

void	cmd_free(t_cmd **lst)
{
	t_cmd	*tmp;
	t_cmd	*next;
	int		i;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (tmp)
	{
		if (tmp->argv)
		{
			i = 0;
			while (tmp->argv[i])
			{
				free(tmp->argv[i]);
				i++;
			}
			free(tmp->argv);
		}
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}

void	open_files(t_pipex *data)
{
	data->infile_fd = open(data->infile, O_RDONLY);
	if (data->infile_fd < 0)
	{
		perror(data->infile);
		exit(EXIT_FAILURE);
	}
	data->outfile_fd = open(data->outfile, O_CREAT, O_WRONLY, O_APPEND, 0644);
	if (data->outfile_fd < 0)
	{
		perror(data->outfile);
		close(data->infile_fd);
		exit(EXIT_FAILURE);
	}
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
