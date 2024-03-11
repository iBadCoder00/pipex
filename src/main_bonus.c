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

int	here_doc(char *temp_name, char *limiter)
{
	int		p[2];
	char	*s;
	size_t	lim_len;

	pipe(p);
	lim_len = ft_strlen(limiter);
	if (!lim_len)
		limiter = ft_strdup("\n");
	while (1)
	{
		write(1, "> ", 2);
		s = get_next_line(READ);
		if (ft_strncmp(s, limiter, ft_strlen(limiter)) == 0)
		{
			free(s);
			break ;
		}
		ft_putstr_fd(s, p[WRITE]);
		free(s);
	}
	if (!lim_len)
		free(limiter);
	dup2(p[READ], STDIN_FILENO);
	close(p[READ]);
	close(p[WRITE]);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_in;
	char	**env_paths;

	env_paths = get_envpaths(envp);
	arg_check(argc, argv);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		here_doc(TEMP_NAME, argv[2]);
		pipe_cmds(argc - 3, env_paths, argv + 3, envp);
	}
	else
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in < 0)
			ft_perror(NO_EXP_FILE);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		pipe_cmds(argc - 2, env_paths, argv + 2, envp);
	}
	return (0);
}
