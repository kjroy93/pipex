/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 19:23:15 by kmarrero          #+#    #+#             */
/*   Updated: 2025/09/29 19:15:05 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	special_wait(pid_t *pids, int n)
{
	int	status;
	int	exit_code;
	int	i;

	i = 0;
	while (i < n)
	{
		if (waitpid(pids[i], &status, 0) == -1)
			perror("waitpid");
		if (i == n - 1 && WIFEXITED(status))
			exit_code = WEXITSTATUS(status);
		i++;
	}
	return (exit_code);
}
