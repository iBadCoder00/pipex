/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <adavila-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:36:31 by adavila-          #+#    #+#             */
/*   Updated: 2024/03/05 16:36:31 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H
# define BAD_PIPE "Something went wrong while creating a pipe."
# define BAD_FORK "Could not create fork."
# define BAD_CMD "Command not found: "
# define BAD_FILE "No such file: "
# define BAD_PATH "Could find a suitable path in ENV"
# define NO_EXP_FILE "Something went wrong while opening a file"
# define NO_EXP_CMD "Something went wrong while processing a command"
# define USAGE "Usage: ./pipex [INFILE] [CMD] [CMD] [OUTFILE]"
# define USAGE_B "Usage: ./pipex_b [INFILE] [COMMANDS]... [OUTFILE]\n\
For here_doc information use ./pipex_b --here."
# define HDOC_USE "here_doc usage: ./pipex_b here_doc [LIMITER]\
 [COMMANDS]... [OUTFILE]"
#endif