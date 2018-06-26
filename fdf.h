/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cholm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:05:05 by cholm             #+#    #+#             */
/*   Updated: 2018/03/14 12:38:24 by cholm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# define WINX 3100
# define WINY 1600

typedef struct		s_point
{
	void		*mlx;
	void		*win;
	void		*image;
	int			ref_x;
	int			ref_y;
	int			**tab;
	int			color;
	int			zoom;
	int			zoom_y;
	double		h_z;
	char		*data;
	int			opp;
	int			sizeline;
	int			endian;
	int			size_x;
	int			size_y;
}					t_point;

typedef struct		s_coord
{
	int x;
	int y;
	int z;
}					t_coord;

typedef struct		s_bres
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		error;
}					t_bres;

int					**file_parser(int fd, char *line, char *argv);
void				ft_color(int keycode, t_point *elem);
void				ft_move(int keycode, t_point *elem);
int					key_function(int keycode, t_point *elem);
void				in_tab(t_point *elem, int x, int y, int l);
void				ft_init_mlx(t_point *elem);
void				ft_init_mlx2(t_point *elem);
void				put_pixel_to_image(t_point *elem, int x, int y, int color);
int					ft_abs(int value);
void				ft_draw(t_point *elem, t_coord *p1, t_coord *p2);
t_coord				*get_coord(int y, int x, int z, t_point *mlx);
int					ft_check_file(char *argv);
int					red_cross(t_point *elem);
void				ft_loop(t_point *elem);
#endif
