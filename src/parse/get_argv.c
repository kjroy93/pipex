/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:45:54 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/27 21:36:03 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
