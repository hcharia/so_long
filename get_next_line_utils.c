/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:34:33 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 15:47:36 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_strchr(char *s, char a)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == a)
			return (i);
		i++;
	}
	if (a == '\0')
		return (i);
	return (0);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s = malloc(my_strchr(s1, '\0') + my_strchr(s2, '\0') + 1);
	if (!s)
		return (NULL);
	while (s1[++i] != '\0')
		s[i] = s1[i];
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}

char	*readfile(char *stat, int fd)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (i != 0 && !my_strchr(stat, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(stat);
			stat = NULL;
			break ;
		}	
		buff[i] = '\0';
		stat = my_strjoin(stat, buff);
	}
	free(buff);
	return (stat);
}

char	*takeline(char *stat)
{
	char	*line;
	int		i;

	i = 0;
	if (!stat[i])
		return (NULL);
	while (stat[i] && stat[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stat[i] != '\n' && stat[i])
	{
		line[i] = stat[i];
		i++;
	}	
	if (stat[i] == '\n')
	{
		line[i] = stat[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rest(char *stat)
{
	char	*rst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stat[i] && stat[i] != '\n')
		i++;
	if (!stat[i])
	{
		free(stat);
		return (NULL);
	}
	rst = malloc (my_strchr(stat, '\0') - i + 1);
	if (!rst)
	{
		free(rst);
		return (NULL);
	}
	i++;
	while (stat[i] != '\0')
		rst[j++] = stat[i++];
	rst[j] = '\0';
	free (stat);
	return (rst);
}
