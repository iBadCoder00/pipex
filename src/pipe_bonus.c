/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:42:55 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/05 16:42:55 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe.h"

/*Basic function run at the start of the program 
to check wheter all starting condition are met*/
void	arg_check(int argc, char **argv)
{
	int	infile;

	if (argc == 2 && ft_strncmp(argv[1], "--here", 6) == 0)
		ft_perror(HDOC_USE);
	if (argc < 5)
		ft_perror(USAGE_B);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) != 0)
	{
		infile = open(argv[1], O_RDONLY);
		if (infile < 0)
			ft_perror(ft_strjoin(BAD_FILE, argv[1]));
		close(infile);
	}
}

/*Creates a child that will read from the 
open pipe that the parent process left open 
and will dump its command output into the writing end of the pipe*/
void	create_child(char *cmd_path, char **cmd, char **envp)
{
	int	p[2];
	int	pid;

	if (pipe(p) < 0)
		ft_perror(NO_EXP_CMD);
	pid = fork();
	if (pid < 0)
		ft_perror(NO_EXP_CMD);
	if (pid == 0)
	{
		close(p[READ]);
		dup2(p[WRITE], STDOUT_FILENO);
		close(p[WRITE]);
		if (execve(cmd_path, cmd, envp) < 0)
			ft_perror(ft_strjoin(BAD_CMD, cmd[0]));
	}
	else
	{
		dup2(p[READ], STDIN_FILENO);
		close(p[READ]);
		close(p[WRITE]);
	}
}

/*Driver function that lets the child processes execute every command and pass
the output generated between them until the last command,
which is handled by the parent process in order to 
flush the output generated from the pipeline into the output file*/
void	pipe_cmds(int argc, char **env_paths, char **argv, char **envp)
{
	int		i;
	int		fd_out;
	char	**cmd;
	char	*cmd_path;

	i = 0;
	while (i < argc - 1)
	{
		cmd_path = cmd_check(argv[i], env_paths);
		cmd = ft_split(argv[i], ' ');
		if (i == argc - 2)
		{
			fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd_out, STDOUT_FILENO);
			if (execve(cmd_path, cmd, NULL) < 0)
				ft_perror(ft_strjoin(BAD_CMD, cmd[0]));
			close (fd_out);
		}
		else
			create_child(cmd_path, cmd, envp);
		free_tab(cmd);
		free(cmd_path);
		i++;
	}
	free_tab(env_paths);
}

/*Tries to find the executable path for the given command.
If a suitable path is not found, the program will return null.*/
char	*cmd_check(char *argv, char **path)
{
	int		i;
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(argv, ' ');
	if (access(cmd[0], F_OK) == 0)
	{
		cmd_path = ft_strdup(cmd[0]);
		free_tab(cmd);
		return (cmd_path);
	}
	i = 0;
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd[0]);
		if (access(cmd_path, F_OK) == 0)
		{
			free_tab(cmd);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_tab(cmd);
	return (0);
}

/*Parses the enviroment pointer variable and tries 
to find a suitable path to access in order to execute the commands*/
char	**get_envpaths(char **envp)
{
	int		i;
	char	**env_paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i] == NULL)
		ft_perror(BAD_PATH);
	env_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		env_paths[i] = ft_strapp(env_paths[i], "/");
		i++;
	}
	return (env_paths);
}
