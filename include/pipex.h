/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:25:08 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/31 13:37:58 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <sys/wait.h>

typedef struct s_cmd
{
	char			**argv;
	int				index;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipex
{
	char	*outfile;
	char	*infile;
	int		heredoc;
	int		n_cmds;
	int		infile_fd;
	int		outfile_fd;
	t_cmd	*cmds;
}	t_pipex;

void	cmd_add_back(t_cmd **lst, t_cmd *new);
void	get_commands(int argc, char **argv, t_pipex *data);
char	**split_with_quotes(const char *s);
t_cmd	*prepare_node(char *cmd_str, int i);
void	cmd_free(t_cmd **lst);
char	**split_with_quotes(const char *s);
char	*define_path(char *cmd, char **envp);
void	free_matrix(char **matrix);
int		open_files(t_pipex *data);
void	redirect_infile(int fd);
void	redirect_outfile(int fd);
void	redirect_pipe_in(int read_fd);
void	redirect_pipe_out(int write_fd);
void	pater_familias(t_pipex *data, char **envp);

#endif