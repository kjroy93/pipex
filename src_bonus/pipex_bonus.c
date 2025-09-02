/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:29:49 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/02 21:29:13 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *data, int argc, char **argv)
{
	data->heredoc = 0;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	get_commands(argc, argv, data);
}

int	main_bonus(int argc, char **argv, char **envp)
{
	t_pipex	*data;

	if (argc < 5)
		return (write(2, "Error: not sufficient arguments.\n", 34), 1);
	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror("malloc for data structure not done");
		return (1);
	}
	init_pipex(data, argc, argv);
	data->envp = envp;
	if (open_files(data) == 1)
	{
		cmd_free(&data->cmds);
		free(data);
		return (1);
	}
	pater_familias(data, envp);
	cmd_free(&data->cmds);
	free_matrix(data->envp);
	free(data);
	return (0);
}
