/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:07:03 by qcosta            #+#    #+#             */
/*   Updated: 2022/12/20 16:44:49 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process1(t_data *data, char **envp)
{
	if (!data->cmd_arg1)
		ft_error(data);
	data->cmd_path = true_path(data, data->cmd_arg1);
	if (!data->cmd_path)
		data->cmd_path = path(data, envp, data->cmd_arg1[0]);
	if (data->infile < 0)
		ft_error(data);
	dup2(data->infile, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	if (!data->cmd_path)
	{
		ft_putstr_fd(data->cmd_arg1[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_error(data);
	}
	if (data->infile > 2)
		close(data->infile);
	if (data->outfile > 2)
		close(data->outfile);
	execve(data->cmd_path, data->cmd_arg1, envp);
	ft_error(data);
}

void	child_process2(t_data *data, char **envp)
{
	if (!data->cmd_arg2)
		ft_error(data);
	data->cmd_path = true_path(data, data->cmd_arg2);
	if (data->cmd_path == NULL)
		data->cmd_path = path(data, envp, data->cmd_arg2[0]);
	if (data->outfile < 0)
		ft_error(data);
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->fd[0]);
	close(data->fd[1]);
	if (!data->cmd_path)
	{
		ft_putstr_fd(data->cmd_arg2[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_error(data);
	}
	execve(data->cmd_path, data->cmd_arg2, envp);
	ft_error(data);
}

int	parent(t_data *data, char **envp)
{
	pipe(data->fd);
	data->child1 = fork();
	if (data->child1 < 0)
		return (-1);
	if (data->child1 == 0)
		child_process1(data, envp);
	else if (data->child1 > 0)
	{
		data->child2 = fork();
		if (data->child2 == 0)
			child_process2(data, envp);
		close(data->fd[1]);
		close(data->fd[0]);
		free_strs(data->cmd_arg1, NULL);
		free_strs(data->cmd_arg2, NULL);
		waitpid(data->child1, NULL, 0);
		waitpid(data->child2, NULL, 0);
	}
	return (0);
}
