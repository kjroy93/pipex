/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:05:50 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/24 15:16:02 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_commands(t_cmd *cmds)
{
	int i = 0;
	t_cmd *tmp = cmds;

	while (tmp)
	{
		printf("Comando %d: ", i);
		for (int j = 0; tmp->argv[j]; j++)
			printf("%s ", tmp->argv[j]);
		printf("\n");
		tmp = tmp->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_pipex	*data;

	data = malloc(sizeof(t_pipex));
	data->heredoc = 0;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	get_commands(argc, argv, data);
	print_commands(data->cmds);
	cmd_free(&data->cmds);
	free(data);
	return (0);
}
