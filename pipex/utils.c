/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:33:45 by qcosta            #+#    #+#             */
/*   Updated: 2022/12/20 16:46:26 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(t_data *data)
{
	if (data->infile > 2)
		close(data->infile);
	if (data->outfile > 2)
		close(data->outfile);
	if (data->fd[0] > 2)
		close(data->fd[0]);
	if (data->fd[1] > 2)
		close(data->fd[1]);
}

void	ft_error(t_data *data)
{
	ft_close_fd(data);
	free_strs(data->cmd_arg2, NULL);
	free_strs(data->cmd_arg1, NULL);
	if (data->cmd_path)
		free(data->cmd_path);
	exit(127);
}

void	ft_init(t_data *data, char **argv)
{
	data->cmd_path = NULL;
	if (ft_strlen(argv[2]) == 0)
		data->cmd_arg1 = NULL;
	else
		data->cmd_arg1 = ft_split(argv[2], ' ');
	if (ft_strlen(argv[3]) == 0)
		data->cmd_arg2 = NULL;
	else
		data->cmd_arg2 = ft_split(argv[3], ' ');
}
