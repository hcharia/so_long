/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharia < hcharia@student.1337.ma>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:50:16 by hcharia           #+#    #+#             */
/*   Updated: 2023/03/02 18:32:04 by hcharia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	samelengh(char **s)
{
	int				i;
	unsigned int	lengh;

	i = 1;
	lengh = ft_strlen(s[0]);
	while (s[i])
	{
		if (ft_strlen(s[i]) != lengh)
			return (1);
		i++;
	}
	return (0);
}

int	ft_doublelen(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	checkarg(char *s)
{
	char	*e;
	int		i;
	int		j;

	i = ft_strlen(s) - 1;
	j = 0;
	e = "reb.";
	if (ft_strlen(s) < 4)
		return (1);
	while (j < 4)
	{
		if (s[i] != e[j])
			return (1);
		i--;
		j++;
	}
	return (0);
}

int	map2dcheck(char **s)
{
	int	i;

	i = 1;
	if (ft_doublelen(s) < 3)
		return (1);
	if (filledwithone(s[0]) || filledwithone(s[ft_doublelen(s) - 1]))
		return (1);
	while (i < ft_doublelen(s) - 1)
	{
		if (startandend1(s[i]))
			return (1);
		i++;
	}
	if (samelengh(s))
		return (1);
	return (0);
}

int	*whereisit(char **p, char c)
{
	int	i;
	int	j;
	int	*s;

	s = malloc (sizeof(int *) * 2);
	if (!s)
		return (NULL);
	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			if (p[i][j] == c)
			{
				s[0] = i;
				s[1] = j;
				return (s);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
