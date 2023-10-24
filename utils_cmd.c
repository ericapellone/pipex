/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epellone <epellone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:35:52 by epellone          #+#    #+#             */
/*   Updated: 2023/10/23 15:26:09 by epellone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	checkdel(char c, char del)
{
	if (c == del || c == '\0')
		return (1);
	return (0);
}

int	count_chars(char *str, char del)
{
	int	x;
	int	chars;

	x = 0;
	chars = 0;
	while (str[x] != '\0')
	{
		if (checkdel(str[x + 1], del) == 1 && checkdel(str[x], del) == 0)
			chars++;
		x++;
	}
	return (chars);
}

void	write_word(char *dst, char *src, char del)
{
	int	i;

	i = 0;
	while (checkdel(src[i], del) == 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	substrs(char **arr, char *arg, char del)
{
	int	i;
	int	j;
	int	sep;

	sep = 0;
	i = 0;
	while (arg[i] != '\0')
	{
		if (checkdel(arg[i], del) == 1)
			i++;
		else
		{
			j = 0;
			while (checkdel(arg[i + j], del) == 0)
				j++;
			arr[sep] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(arr[sep], arg + i, del);
			i = i + j;
			sep++;
		}
	}
}

char	**ft_split(char const *arg, char del)
{
	char	**strarray;
	char	*str;
	int		words;

	if (arg == NULL)
		return (NULL);
	str = (char *)arg;
	words = count_chars(str, del);
	strarray = (char **)malloc(sizeof(char *) * (words + 1));
	if (strarray == NULL)
		return (NULL);
	strarray[words] = 0;
	substrs(strarray, str, del);
	return (strarray);
}
