/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:23:23 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/26 18:07:35 by kjroy93          ###   ########.fr       */
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
	char	**envp;
	int		outfile_fd;
	int		infile_fd;
	int		pipe_fd[2];
	int		heredoc;
	int		n_cmds;
	t_cmd	*cmds;
	pid_t	*pids;
}	t_pipex;

t_cmd	*prepare_node(char *cmd_str, int i);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
void	cmd_free(t_cmd **lst);
void	free_matrix(char **matrix);
void	get_commands(int argc, char **argv, t_pipex *data);
char	**split_with_quotes(const char *s);
void	perror_free(t_pipex *data, t_cmd *cmd, char *path);
char	*define_path(char *cmd, char **envp);
int		special_wait(pid_t *pids, int n);
void	get_commands_here_doc(int argc, char **argv, t_pipex *data);
void	redirect_infile(int fd, t_pipex *data);
void	redirect_outfile(int fd, t_pipex *data);
void	redirect_pipe_in(int read_fd, t_pipex *data);
void	redirect_pipe_out(int write_fd, t_pipex *data);
int		open_files(t_pipex *data);
void	free_pipex(t_pipex *data);
void	execute(t_cmd *cmd, t_pipex *data);
int		pater_familias(t_pipex *data);
int		pater_familias_bonus(t_pipex *data);
void	first_child_bonus(t_pipex *data, t_cmd *cmd);
void	mid_child_bonus(t_pipex *data, int *fd_in);
void	last_child_bonus(t_pipex *data, int *fd_in);

#endif
