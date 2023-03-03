/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:05:47 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:28:48 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

char	*mapline(char *str)
{
	int		fd;
	char	*result;
	char	*v;

	v = malloc (0);
	v[0] = '\0';
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	result = get_next_line(fd);
	if (!result)
		return (NULL);
	while (result != NULL)
	{
		v = my_strjoin(v, result);
		free (result);
		result = get_next_line(fd);
	}
	return (v);
}

int	amountofchar(char *v, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (v[i])
	{
		if (v[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	checkmap(char *v)
{
	int	i;

	if (!v)
		return (1);
	i = 1;
	if (v[0] == '\n' || v[ft_strlen(v) - 1] == '\n'
		|| amountofchar (v, 'C') < 1
		|| amountofchar (v, 'E') != 1
		|| amountofchar (v, 'P') != 1)
		return (1);
	while (v[i])
	{
		if ((v[i] == '\n' && v[i - 1] == '\n'))
			return (1);
		if (v[i] != 'E' && v[i] != 'P'
			&& v[i] != 'C' && v[i] != '1' && v[i] != '\n' && v[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	filledwithone(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	startandend1(char *s)
{
	if (s[0] != '1' || s[ft_strlen(s) - 1] != '1')
		return (1);
	return (0);
}
