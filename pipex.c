/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:06:20 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/25 21:01:56 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *data, int argc, char **argv)
{
	data->heredoc = 0;
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->pids = NULL;
	get_commands(argc, argv, data);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	int		exit_code;

	if (argc != 5)
		return (write(2, "Error: incorrect number of arguments.\n", 34), 1);
	data = malloc(sizeof(t_pipex));
	if (!data)
	{
		perror("malloc for data structure not done");
		return (1);
	}
	init_pipex(data, argc, argv);
	if (open_files(data) == 1)
	{
		cmd_free(&data->cmds);
		free(data);
		return (1);
	}
	exit_code = pater_familias(data, envp);
	free_pipex(data);
	return (exit_code);
}
