/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 09:25:08 by kjroy93           #+#    #+#             */
/*   Updated: 2025/08/27 21:36:58 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

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
	t_cmd	*cmds;
}	t_pipex;

void	cmd_add_back(t_cmd **lst, t_cmd *new);
void	get_commands(int argc, char **argv, t_pipex *data);
char	**split_with_quotes(const char *s);
t_cmd	*prepare_node(char *cmd_str, int i);
void	cmd_free(t_cmd **lst);

#endif