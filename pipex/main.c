/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcosta <qcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:19:13 by qcosta            #+#    #+#             */
/*   Updated: 2022/12/20 16:40:26 by qcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc == 5)
	{
		ft_init(&data, argv);
		data.infile = open(argv[1], O_RDONLY);
		if (data.infile < 0)
			perror("Error File");
		data.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (data.outfile < 0)
			perror("Error File");
		parent(&data, envp);
		if (data.infile > 2)
			close(data.infile);
		if (data.outfile > 2)
			close(data.outfile);
	}
	else
		write(2, "Invalid number of arguments.\n", 29);
	return (0);
}
