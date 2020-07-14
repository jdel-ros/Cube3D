/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:34:20 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/10 16:34:36 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int			ft_dir_up_left(t_cube *cube)
{
	double olddirx;
	double oldplanex;

	olddirx = cube->dirx;
	oldplanex = cube->planex;
	cube->dirx = (cube->dirx * cos(cube->rotspeed)) -
				(cube->diry * sin(cube->rotspeed));
	cube->diry = (olddirx * sin(cube->rotspeed)) +
				(cube->diry * cos(cube->rotspeed));
	cube->planex = (cube->planex * cos(cube->rotspeed)) -
				(cube->planey * sin(cube->rotspeed));
	cube->planey = (oldplanex * sin(cube->rotspeed) +
				cube->planey * cos(cube->rotspeed));
	return (0);
}

int			ft_dir_up_right(t_cube *cube)
{
	double olddirx;
	double oldplanex;

	olddirx = cube->dirx;
	oldplanex = cube->planex;
	cube->dirx = (cube->dirx * cos(-cube->rotspeed)) -
				(cube->diry * sin(-cube->rotspeed));
	cube->diry = (olddirx * sin(-cube->rotspeed)) +
				(cube->diry * cos(-cube->rotspeed));
	cube->planex = (cube->planex * cos(-cube->rotspeed)) -
				(cube->planey * sin(-cube->rotspeed));
	cube->planey = (oldplanex * sin(-cube->rotspeed)) +
				(cube->planey * cos(-cube->rotspeed));
	return (0);
}

void		ft_collision(t_cube *cube, t_vector futur_move)
{
	cube->perm.x = 1;
	cube->perm.y = 1;
	if (cube->worldmap[(int)(cube->posx)]
		[(int)(futur_move.y + cube->posy)] >= 1)
		cube->perm.y = 0;
	else
		cube->perm.y = 1;
	if (cube->worldmap[(int)(futur_move.x + cube->posx)]
		[(int)(cube->posy)] >= 1)
		cube->perm.x = 0;
	else
		cube->perm.x = 1;
}
