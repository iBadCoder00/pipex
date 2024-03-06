/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:39:07 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/05 16:39:07 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H
# define READ 0
# define WRITE 1
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"
# include "error.h"

int		ft_perror(char *error_message);
char	**get_envpaths(char **envp);
char	*cmd_check(char *argv, char **path);
char	*ft_strapp(char *s1, char *s2);
void	arg_check(int argc, char **argv);
void	create_child(char *cmd_path, char **cmd, char **envp);
void	free_tab(char **tab);
void	pipe_cmds(int argc, char **env_paths, char **argv, char **envp);
#endif // PIPE_H
