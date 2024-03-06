/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:45:23 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/05 16:45:23 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	char	**env_paths;

	arg_check(argc, argv);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		ft_perror(NO_EXP_FILE);
	env_paths = get_envpaths(envp);
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	pipe_cmds(argc, env_paths, argv, envp);
	return (0);
}
