/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:03:45 by cholm             #+#    #+#             */
/*   Updated: 2018/06/14 12:34:34 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		atoi_in_tab(char *str, int **tab, int k, int size)
{
	int		i;
	int		j;
	int		l;
	char	**temp;

	i = 0;
	j = 2;
	l = 0;
	temp = ft_strsplit(str, ' ');
	while (temp[i])
		i++;
	if (!(tab[k] = (int *)malloc(sizeof(int) * (i + 2))))
		return (0);
	while (j < i + 2)
	{
		tab[k][0] = size;
		tab[k][1] = i;
		tab[k][j++] = ft_atoi(temp[l++]);
	}
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(temp);
	return (i);
}

int				**file_parser(int fd, char *line, char *argv)
{
	int i;
	int size;
	int **tab;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		free(line);
	}
	free(line);
	size = i;
	close(fd);
	if (!(tab = (int **)malloc(sizeof(int *) * (i))))
		return (0);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		atoi_in_tab(line, tab, i++, size);
		free(line);
	}
	free(line);
	close(fd);
	return (tab);
}
