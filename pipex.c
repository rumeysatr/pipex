/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutatar <rutatar@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:44:45 by rutatar           #+#    #+#             */
/*   Updated: 2024/01/29 15:24:40 by rutatar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "pipex.h"
#include <stdio.h>

void	impl(char *cmd, char **env)
{
	char	**cmd3;
	char	*path;

	cmd3 = ft_split(cmd, ' ');
	if (!cmd3)
		return (ft_free_tab(cmd3));
	path = get_path(cmd3[0], env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd3[0], 2);
		ft_free_tab(cmd3);
		exit(EXIT_FAILURE);
	}
	execve(path, cmd3, env);
	ft_free_tab(cmd3);
	exit(0);
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("pid");
	else if (pid == 0)
	{
		fd = open_file(av[1], 0);
		dup2(fd, 0);
		close(fd);
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		close(p_fd[1]);
		impl(av[2], env);
	}
	close(p_fd[1]);
	wait(NULL);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("pid");
	else if (pid == 0)
	{
		fd = open_file(av[4], 1);
		dup2(fd, 1);
		close(fd);
		dup2(p_fd[0], 0);
		close(p_fd[0]);
		impl(av[3], env);
	}
	wait(NULL);
	close(p_fd[0]);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];

	if (ac != 5)
		return (msg(ERR_INPUT));
	if (pipe(p_fd) == -1)
		perror("pipe");
	child(av, p_fd, env);
	parent(av, p_fd, env);
}
