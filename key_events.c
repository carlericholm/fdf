/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:06:08 by cholm             #+#    #+#             */
/*   Updated: 2018/01/29 21:08:15 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_color(int keycode, t_point *elem)
{
	if (keycode == 83)
		elem->color = 0x00148F01;
	if (keycode == 84)
		elem->color = 0x00FFFFFF;
	if (keycode == 85)
		elem->color = 0x00FF0000;
	if (keycode == 86)
		elem->color = 0x00FF7900;
	if (keycode == 87)
		elem->color = 0x000000FF;
	if (keycode == 88)
		elem->color = 0x00FEFE2C;
	if (keycode == 89)
		elem->color = 0x00F050FF;
	if (keycode == 91)
		elem->color = 0x00401F6C;
	if (keycode == 92)
		elem->color = 0x0040FC04;
	if (keycode == 53)
		exit(1);
}

int			red_cross(t_point *elem)
{
	ft_memdel((void**)&elem);
	free(elem);
	exit(0);
}

void		ft_move(int keycode, t_point *elem)
{
	if (keycode == 35)
		elem->h_z += 0.1;
	if (keycode == 46)
		elem->h_z -= 0.1;
	if (keycode == 123)
		elem->ref_x -= 20;
	if (keycode == 124)
		elem->ref_x += 20;
	if (keycode == 125)
		elem->ref_y += 20;
	if (keycode == 126)
		elem->ref_y -= 20;
	if (keycode == 78)
	{
		if (elem->zoom - 3 > 0)
		{
			elem->zoom -= 3;
			elem->zoom_y -= 3;
		}
	}
	if (keycode == 69)
	{
		elem->zoom += 3;
		elem->zoom_y += 3;
	}
}

void		ft_loop(t_point *elem)
{
	int x;
	int y;
	int l;

	x = 2;
	y = 0;
	l = 2;
	ft_init_mlx(elem);
	in_tab(elem, x, y, l);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->image, 0, 0);
	mlx_key_hook(elem->win, key_function, elem);
	mlx_hook(elem->win, 17, (1L << 17), red_cross, elem);
	mlx_loop(elem->mlx);
}

int			key_function(int keycode, t_point *elem)
{
	int x;
	int y;
	int l;
	int bpp;

	x = 2;
	y = 0;
	l = 2;
	mlx_clear_window(elem->mlx, elem->win);
	mlx_destroy_image(elem->mlx, elem->image);
	elem->image = mlx_new_image(elem->mlx, WINX, WINY);
	elem->data = mlx_get_data_addr(elem->image,
			&bpp, &elem->sizeline, &elem->endian);
	elem->opp = bpp / 8;
	ft_move(keycode, elem);
	ft_color(keycode, elem);
	in_tab(elem, x, y, l);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->image, 0, 0);
	return (0);
}
