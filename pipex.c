/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:38:19 by epellone          #+#    #+#             */
/*   Updated: 2023/10/23 23:24:06 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(const char *message)
{
	perror(message);
	exit(1);
}

void	ft_childprocess(char **argv, char **envp, int *fd)
{
	int	input;

	input = open(argv[1], O_RDONLY, 0777);
	if (input == -1)
		error("filein error");
	dup2(fd[1], 1);
	dup2(input, 0);
	close(fd[0]);
	ft_cmd(argv[2], envp);
}

void	ft_parentprocess(char **argv, char **envp, int *fd)
{
	int	output;

	output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output == -1)
		error("fileout error");
	dup2(fd[0], 0);
	dup2(output, 1);
	close(fd[1]);
	ft_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		status;
	pid_t	child_pid;

	if (argc == 5)
	{
		pipe(fd);
		if (pipe(fd) == -1)
			error("pipe error");
		child_pid = fork();
		if (child_pid == -1)
			error("fork error");
		if (child_pid == 0)
			ft_childprocess(argv, envp, fd);
		waitpid(child_pid, &status, 0);
		ft_parentprocess(argv, envp, fd);
	}
	else
		error("argv error");
	return (0);
}
