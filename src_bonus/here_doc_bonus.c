/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:05:56 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/18 21:07:23 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*read_fd_0(char *limiter)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
		return (NULL);
	if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
		&& ft_strlen(line) == ft_strlen(limiter) + 1
		&& line[ft_strlen(limiter)] == '\n')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

void	get_commands_here_doc(int argc, char **argv, t_pipex *data)
{
	char	*limiter;
	char	*line;
	int		tmp_fd;

	(void)argc;
	limiter = argv[2];
	tmp_fd = open((".heredoc_tmp"), O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (tmp_fd < 0)
		perror_exit("Error with open in heredoc_tmp.\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = read_fd_0(limiter);
		if (line)
		{
			write(tmp_fd, line, ft_strlen(line));
			free(line);
		}
		else
			break ;
	}
	close(tmp_fd);
	data->infile = ".heredoc_tmp";
	get_commands(argc, argv, data);
}
