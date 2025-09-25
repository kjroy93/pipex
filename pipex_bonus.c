/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:06:15 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/25 21:09:32 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *data, int argc, char **argv, char **envp)
{
	data->envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		data->heredoc = 1;
		data->infile = NULL;
		data->outfile = argv[argc - 1];
		get_commands_here_doc(argc, argv, data);
	}
	else
	{
		data->heredoc = 0;
		data->infile = argv[1];
		data->outfile = argv[argc - 1];
		get_commands(argc, argv, data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*data;
	int		exit_code;

	if (argc < 4)
		return (write(2, "Error: not sufficient arguments.\n", 34), 1);
	data = malloc(sizeof(t_pipex));
	if (!data)
		perror_exit("malloc for data structure in main not done.\n");
	init_pipex(data, argc, argv, envp);
	if (open_files(data) == 1)
	{
		cmd_free(&data->cmds);
		free(data);
		return (1);
	}
	exit_code = pater_familias_bonus(data);
	if (data->heredoc)
		unlink(".heredoc_tmp");
	free_pipex(data);
	return (exit_code);
}
