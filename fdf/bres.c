/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:12:40 by cholm             #+#    #+#             */
/*   Updated: 2018/01/23 17:06:20 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    put_pixel_to_image(t_point *elem, int x, int y, int color)
{
	*((int *)&elem->data[(x * elem->opp) + (y * elem->sizeline)]) = color;
}



int     ft_abs(int value)
{
	return (value < 0 ? (-value) : (value));
}


t_bres     *ft_init_bres(t_coord *p1, t_coord *p2)
{
	t_bres *bres;

	if (!(bres = (t_bres *)malloc(sizeof(t_bres))))
		return (NULL);
	bres->x1 = ft_abs(p2->x - p1->x);
	bres->x2 = (p1->x < p2->x) ? 1 : -1;
	bres->y1 = ft_abs(p2->y - p1->y);
	bres->y2 = (p1->y < p2->y) ? 1 : -1;
	bres->error = (bres->x1 > bres->y1 ? bres->x1 : -(bres->y1)) / 2;
	return (bres);
}


void                ft_draw(t_point *elem, t_coord *p1, t_coord *p2)
{
	int     x;
	int     y;
	int     ret;
	t_bres *bres;

	bres = ft_init_bres(p1, p2);
	x = p1->x;
	y = p1->y;
	while (1)
	{
		if ((x >= 0 && x < WINX) && (y >= 0 && y < WINY))
			put_pixel_to_image(elem, x, y, elem->color);
		if (x == p2->x && y == p2->y)
			break ;
		if ((ret = bres->error) > -(bres->x1))
		{
			bres->error -= bres->y1;
			x += bres->x2;
		}
		if (ret < bres->y1)
		{
			bres->error += bres->x1;
			y += bres->y2;
		}
	}
}

t_coord         *get_coord(int y, int x, int z, t_point *mlx)
{
	t_coord *elem;

	elem = (t_coord *)malloc(sizeof(t_coord));
	elem->x = ((x - y) * mlx->zoom) + mlx->ref_x;
	elem->y = (((y + x) - (z * mlx->h_z)) * mlx->zoom_y) + mlx->ref_y;
	elem->z = z;
	return (elem);
}
