/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:43:17 by qcosta            #+#    #+#             */
/*   Updated: 2022/12/20 16:42:13 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **strs, char *str)
{
	int	i;

	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	if (strs != NULL)
	{
		i = 0;
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
		strs = NULL;
	}
}

char	*search_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	*true_path(t_data *data, char **argv)
{
	if (access(argv[0], X_OK) == 0)
	{
		data->cmd_path = ft_strdup(argv[0]);
		return (data->cmd_path);
	}
	return (NULL);
}

char	*path(t_data *data, char **envp, char *cmd)
{
	int		i;
	char	**split_path;
	char	*tmp;

	i = 0;
	if (search_path(envp) == NULL || !cmd)
		return (NULL);
	split_path = ft_split(search_path(envp) + 5, ':');
	while (split_path[i])
	{
		tmp = ft_strjoin(split_path[i], "/");
		data->cmd_path = ft_strjoin(tmp, cmd);
		free_strs(NULL, tmp);
		if (access(data->cmd_path, X_OK) == 0)
		{
			free_strs(split_path, NULL);
			return (data->cmd_path);
		}
		free_strs(NULL, data->cmd_path);
		i++;
	}
	free_strs(split_path, NULL);
	return (NULL);
}
