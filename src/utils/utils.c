/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:57:10 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/24 14:50:16 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*prepare_node(char **argv, int *start, int i)
{
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (!node)
		return (NULL);
	node->argv = ft_split(argv[*start + i], ' ');
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
