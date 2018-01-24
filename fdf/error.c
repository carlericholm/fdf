/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:08:50 by cholm             #+#    #+#             */
/*   Updated: 2018/01/24 20:21:56 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_file(char *argv)
{
	int i;
	char *str;
	int fd;

	i = 0;
	str = ".fdf";
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			if ((ft_strcmp(str, &argv[i])) == 0)
			{
				if ((fd = open(argv, O_RDONLY)) < 0)
					return (0);
				close(fd);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
