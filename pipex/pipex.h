/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:17:31 by qcosta            #+#    #+#             */
/*   Updated: 2022/12/21 11:23:46 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "LIBFT/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stddef.h>

typedef struct s_data
{
	int		fd[2];
	int		infile;
	int		outfile;
	pid_t	child1;
	pid_t	child2;
	char	**cmd_arg1;
	char	**cmd_arg2;
	char	*cmd_path;
	int		status;
}	t_data;

int		parent(t_data *data, char **envp);
void	child_process1(t_data *data, char **envp);
void	child_process2(t_data *data, char **envp);
void	free_strs(char **strs, char *str);
void	ft_error(t_data *data);

char	*search_path(char **envp);
char	*path(t_data *data, char **envp, char *cmd);

void	ft_init(t_data *data, char **argv);

char	*true_path(t_data *data, char **argv);

#endif