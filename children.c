/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeltran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:17 by bbeltran          #+#    #+#             */
/*   Updated: 2023/06/13 17:50:28 by bbeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex pipex, char *command, char *path)
{
	if (pipex.child1 == 0)
	{
		printf("child 1 process\n");
		close(pipex.pipefd[0]);	
		dup2(pipex.fd1, STDOUT_FILENO);

	}
	
}
