/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:40:58 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/12 15:59:45 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_texture_init(t_cube *cube)
{
	cube->texture.n.ptr = mlx_xpm_file_to_image(cube->mlx, cube->pars.texture_n,
							&cube->texture.n.width, &cube->texture.n.height);
	cube->texture.n.data = (int *)mlx_get_data_addr(cube->texture.n.ptr,
		&cube->texture.n.bpp, &cube->texture.n.sline, &cube->texture.n.endian);
	cube->texture.s.ptr = mlx_xpm_file_to_image(cube->mlx, cube->pars.texture_s,
							&cube->texture.s.width, &cube->texture.s.height);
	cube->texture.s.data = (int *)mlx_get_data_addr(cube->texture.s.ptr,
		&cube->texture.s.bpp, &cube->texture.s.sline, &cube->texture.s.endian);
	cube->texture.e.ptr = mlx_xpm_file_to_image(cube->mlx, cube->pars.texture_e,
							&cube->texture.e.width, &cube->texture.e.height);
	cube->texture.e.data = (int *)mlx_get_data_addr(cube->texture.e.ptr,
		&cube->texture.e.bpp, &cube->texture.e.sline, &cube->texture.e.endian);
	cube->texture.w.ptr = mlx_xpm_file_to_image(cube->mlx, cube->pars.texture_w,
							&cube->texture.w.width, &cube->texture.w.height);
	cube->texture.w.data = (int *)mlx_get_data_addr(cube->texture.w.ptr,
		&cube->texture.w.bpp, &cube->texture.w.sline, &cube->texture.w.endian);
	cube->text_spr.ptr = mlx_xpm_file_to_image(cube->mlx,
	cube->pars.texture_sprite, &cube->text_spr.width, &cube->text_spr.height);
	cube->text_spr.data = (int *)mlx_get_data_addr(cube->text_spr.ptr,
		&cube->text_spr.bpp, &cube->text_spr.sline, &cube->text_spr.endian);
	return (0);
}

char			ft_wall_in_face(t_cube *cube)
{
	if (cube->side == 1)
	{
		if (cube->stepy > 0)
			return ('W');
		else
			return ('E');
	}
	else if (cube->side == 0)
	{
		if (cube->stepx > 0)
			return ('S');
		else
			return ('N');
	}
	return (0);
}

t_img			ft_choose_texture(t_cube *cube)
{
	char ret;

	ret = ft_wall_in_face(cube);
	if (ret == 'W')
		return (cube->texture.w);
	else if (ret == 'E')
		return (cube->texture.e);
	else if (ret == 'S')
		return (cube->texture.s);
	return (cube->texture.n);
}

void			ft_texture_to_image(t_img texture, t_cube *cube, int i)
{
	int it;

	it = (int)(cube->texture.texturey * (double)texture.height) *
	(texture.sline / 4) + (int)(cube->texture.texturex * (double)texture.width);
	cube->img.data[i] = texture.data[it];
}
