/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:52 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/23 18:21:49 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_INPUT "./pipex infile cmd1 cmd2 outfile\n"

# include "libft/libft.h"
# include <unistd.h>

int		main(int ac, char **p_fd, char **env);
int		open_file(char *file, int io);
int		msg(char *err);
char	*get_path(char *cmd, char **env);
char	*ft_getenv(char *name, char **env);
void	ft_free_tab(char **tab);
void	impl(char *cmd, char **env);
void	child(char **av, int *p_fd, char **env);
void	parent(char **av, int *p_fd, char **env);

#endif