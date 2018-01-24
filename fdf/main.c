/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:06:12 by cholm             #+#    #+#             */
/*   Updated: 2018/01/24 21:47:54 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	ft_free_all(t_coord *p1, t_coord *p2, t_coord *p3)
{
	if (p1)
		ft_memdel((void **)p1);
	if (p2)
		ft_memdel((void **)p2);
	if (p3)
		ft_memdel((void **)p3);
}

void	in_tab(t_point *elem)
{
	int x;
	int y;
	int l;
	t_coord     *p1;
	t_coord     *p2;
	t_coord 	*p3;

	x = 2;
	y = 0;
	l = 2;
	while (y < elem->tab[0][0])
	{
		while (x < elem->tab[y][1] + 2)
		{
			p1 = get_coord(y, x, elem->tab[y][l], elem);
			if (y + 1 < elem->tab[0][0])
			{
				p2 = get_coord(y + 1, x, elem->tab[y + 1][l], elem);
				ft_draw(elem, p1, p2);
				free(p2);
			}
			if (x + 1 < elem->tab[y][1] + 2)
			{
				p3 = get_coord(y, x + 1, elem->tab[y][l + 1], elem);
				ft_draw(elem, p1, p3);
				free(p3);
			}
	///	ft_free_all(p1, p2, p3);
			x++;
			l++;
			free(p1);
		}
		x = 2;
		l = 2;
		y++;
	}
}

void		ft_init_mlx(t_point *elem)
{
	int bpp;

	elem->mlx = mlx_init();
	elem->win = mlx_new_window(elem->mlx, WINX, WINY, "mlx 42");
	elem->image = mlx_new_image(elem->mlx, WINX, WINY);
	elem->data = mlx_get_data_addr(elem->image, &bpp, &elem->sizeline, &elem->endian);
	elem->opp = bpp / 8;

}

void		ft_init_mlx2(t_point *elem)
{
	int bpp;

	elem->image = mlx_new_image(elem->mlx, WINX, WINY);
	elem->data = mlx_get_data_addr(elem->image, &bpp, &elem->sizeline, &elem->endian);
	elem->opp = bpp / 8;

}

t_point		*ft_init()
{
	t_point *elem;

	elem = (t_point *)malloc(sizeof(t_point));
	elem->color = 0x00148F01;
	elem->h_z = 0.2;
	elem->ref_x = 1000;
	elem->ref_y = 200;
	elem->zoom = 10;
	elem->zoom_y = 10;
	elem->data = NULL;
	elem->opp = 0;
	elem->sizeline = 0;
	elem->endian = 0;
	return (elem);
}

int            red_cross(t_point  *elem)
{
	    ft_memdel((void**)&elem);
		    free(elem);
			    exit(0);
}


int     main(int argc, char **argv)
{
	t_point *elem;
	int     fd;
	char    *line;

	line = NULL;
	if (argc == 2)
	{
		if (ft_check_file(argv[1]) == 0)
		{
			ft_putendl("Usage: ./fdf map_name.fdf");
			return (0);
		}
		fd = open(argv[1], O_RDONLY);
		elem = ft_init();
		elem->tab = file_parser(fd, line, argv[1]);
		ft_init_mlx(elem);
		in_tab(elem);
		mlx_put_image_to_window(elem->mlx, elem->win, elem->image, 0, 0);
		mlx_key_hook(elem->win, key_function, elem);
		mlx_hook(elem->win, 17, (1L << 17), &red_cross, elem);
		mlx_loop(elem->mlx);
	}
	else
		ft_putendl("Usage: ./fdf map_name.fdf");
	return (0);
}
