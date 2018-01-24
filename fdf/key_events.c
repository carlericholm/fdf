/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:06:08 by cholm             #+#    #+#             */
/*   Updated: 2018/01/24 21:48:42 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void    ft_color(int keycode, t_point *elem)
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
}

void    ft_move(int keycode, t_point *elem)
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
	if (keycode ==  78)
	{
		elem->zoom -= 3;
		elem->zoom_y -= 3;
	}
	if (keycode == 69)
	{
		elem->zoom += 3;
		elem->zoom_y += 3;
	}
	if (keycode == 53)
	{
	//	ft_free_tab((void **)elem->tab);
		free(elem);
		exit(1);
	}
}

int     key_function(int keycode, t_point *elem)
{
	mlx_clear_window(elem->mlx, elem->win);
	mlx_destroy_image(elem->mlx, elem->image);
	ft_init_mlx2(elem);
	printf("keycode -> %d\n", keycode);
	ft_move(keycode, elem);
	ft_color(keycode, elem);
	in_tab(elem);
	mlx_put_image_to_window(elem->mlx, elem->win, elem->image, 0, 0);

	return (0);
}




