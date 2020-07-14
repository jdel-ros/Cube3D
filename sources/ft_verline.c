/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:03:09 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/14 12:12:27 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void			ft_verline_two(t_img texture, int x, t_cube *cube)
{
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < cube->pars.screenheight)
	{
		if (y <= cube->floorsize)
			cube->img.data[x + y * cube->pars.screenwidth] = cube->sky_color;
		else if (y < (cube->pars.screenheight - cube->skysize)
				&& y > cube->floorsize)
		{
			i = y * cube->pars.screenwidth + x;
			cube->texture.texturey = ((double)y - (double)cube->skysize) /
			(double)cube->wallheight;
			ft_texture_to_image(texture, cube, i);
		}
		else
			cube->img.data[x + y * cube->pars.screenwidth] = cube->floor_color;
		y++;
	}
}

void			ft_verline(int h, int x, t_cube *cube)
{
	t_img	texture;

	cube->floorsize = (cube->pars.screenheight - h) / 2;
	texture = ft_choose_texture(cube);
	cube->skysize = cube->floorsize;
	cube->wallheight = (cube->pars.screenheight) -
						cube->skysize - cube->floorsize;
	if (ft_wall_in_face(cube) == 'W' || ft_wall_in_face(cube) == 'E')
		cube->texture.texturex = cube->hiit.x - (int)cube->hiit.x;
	else if (ft_wall_in_face(cube) == 'N' || ft_wall_in_face(cube) == 'S')
		cube->texture.texturex = cube->hiit.y - (int)cube->hiit.y;
	ft_verline_two(texture, x, cube);
}

int				ft_print_ray(t_cube *cube)
{
	double		ray_dist;
	int			h;
	int			x;

	x = 0;
	while (x < cube->pars.screenwidth)
	{
		ray_dist = ft_raycasting(cube, x);
		h = (int)(cube->pars.screenheight / ray_dist);
		ft_verline(h, x, cube);
		x++;
	}
	if (cube->perm_save == 1)
	{
		cube->perm_save = 0;
		ft_save_bitmap("cube.bmp", cube);
	}
	ft_raycasting_sprite(cube);
	mlx_put_image_to_window(cube->mlx, cube->window, cube->img.img, 0, 0);
	return (0);
}
