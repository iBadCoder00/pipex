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

void	here_doc(char *limiter, size_t lim_len)
{
	int		p[2];
	char	*s;

	if (pipe(p) < 0)
		ft_perror(BAD_PIPE);
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
	size_t	lim_len;
	char	**env_paths;

	env_paths = get_envpaths(envp);
	arg_check(argc, argv);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		lim_len = ft_strlen(argv[2]);
		if (!lim_len)
			argv[2] = ft_strdup("\n");
		here_doc(argv[2], lim_len);
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
