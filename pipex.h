/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 08:40:36 by epellone          #+#    #+#             */
/*   Updated: 2023/10/23 18:15:37 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <time.h>

void	error(const char *message);
void	ft_cmd(char *argv, char **envp);
void	ft_parentprocess(char **argv, char **envp, int *fd);
void	ft_childprocess(char **argv, char **envp, int *fd);
char	**ft_split(char const *arg, char del);
void	substrs(char **arr, char *arg, char del);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_clean(char **matrix);

#endif