/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:32:08 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/12 19:39:00 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void		ft_raycasting_two(t_cube *cube)
{
	if (cube->raydirx < 0)
	{
		cube->stepx = -1;
		cube->sidedistx = (cube->posx - cube->mapx) * cube->deltadistx;
	}
	else
	{
		cube->stepx = 1;
		cube->sidedistx = (cube->mapx + 1.0 - cube->posx) * cube->deltadistx;
	}
	if (cube->raydiry < 0)
	{
		cube->stepy = -1;
		cube->sidedisty = (cube->posy - cube->mapy) * cube->deltadisty;
	}
	else
	{
		cube->stepy = 1;
		cube->sidedisty = (cube->mapy + 1.0 - cube->posy) * cube->deltadisty;
	}
}

void		ft_raycasting_three(t_cube *cube)
{
	while (cube->hit == 0)
	{
		if (cube->sidedistx < cube->sidedisty)
		{
			cube->sidedistx += cube->deltadistx;
			cube->mapx += cube->stepx;
			cube->side = 0;
		}
		else
		{
			cube->sidedisty += cube->deltadisty;
			cube->mapy += cube->stepy;
			cube->side = 1;
		}
		if (cube->worldmap[cube->mapx][cube->mapy] == 1)
			cube->hit = 1;
	}
	if (cube->side == 0)
		cube->perpwalldist = (cube->mapx - cube->posx + (1 - cube->stepx) / 2)
		/ cube->raydirx;
	else
		cube->perpwalldist = (cube->mapy - cube->posy + (1 - cube->stepy) / 2)
		/ cube->raydiry;
}

double		ft_raycasting(t_cube *cube, int x)
{
	cube->camerax = 2 * x / (double)(cube->pars.screenwidth) - 1;
	cube->raydirx = cube->dirx + cube->planex * cube->camerax;
	cube->raydiry = cube->diry + cube->planey * cube->camerax;
	cube->mapx = (int)cube->posx;
	cube->mapy = (int)cube->posy;
	cube->deltadistx = fabs(1 / cube->raydirx);
	cube->deltadisty = fabs(1 / cube->raydiry);
	cube->hit = 0;
	cube->side = 0;
	ft_raycasting_two(cube);
	ft_raycasting_three(cube);
	cube->hiit.x = cube->posx + cube->raydirx * cube->perpwalldist;
	cube->hiit.y = cube->posy + cube->raydiry * cube->perpwalldist;
	cube->zbuffer[x] = cube->perpwalldist;
	return (cube->perpwalldist);
}
