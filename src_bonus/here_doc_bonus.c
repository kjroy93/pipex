/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:05:56 by kjroy93           #+#    #+#             */
/*   Updated: 2025/09/09 20:09:28 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_commands_here_doc(int argc, char **argv, t_pipex *data)
{
	char	*limiter;
	char	*line;
	int		tmp_fd;

	limiter = argv[2];
	tmp_fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd < 0)
		perror_exit("tmp read failed.\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	close(tmp_fd);
	data->infile = ".heredoc_tmp";
	get_commands(argc, argv, data);
}
