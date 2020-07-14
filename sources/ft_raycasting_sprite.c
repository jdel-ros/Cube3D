/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:27 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 15:10:14 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void		ft_draw_sprite(t_cube *cube)
{
	t_color		color;
	size_t		d;
	int			y;

	y = 0;
	y = cube->draw_start_y - 1;
	while (++y < cube->draw_end_y)
	{
		d = y * 256 - cube->pars.screenheight * 128 + cube->sp_h * 128;
		cube->tex_y = ((d * cube->text_spr.height) / cube->sp_h) / 256;
		color.color =
		cube->text_spr.data[cube->text_spr.width * cube->tex_y + cube->tex_x];
		if ((color.color & 0xffffff) != 0)
			cube->img.data[y * cube->pars.screenwidth + cube->stripe] =
			color.color;
	}
}

void		ft_sort_two(t_cube *cube)
{
	while (cube->j < cube->nb_sprite)
	{
		while (cube->i < cube->nb_sprite)
		{
			if (cube->sprites.dist < cube->sprites.dist)
			{
				cube->swapx = cube->sprites.posx;
				cube->swapy = cube->sprites.posy;
				cube->swapdist = cube->sprites.dist;
				cube->sprites = cube->sprites;
				cube->sprites.posx = cube->swapx;
				cube->sprites.posy = cube->swapy;
				cube->sprites.dist = cube->swapdist;
			}
			cube->i++;
		}
		cube->j++;
		cube->i = cube->j + 1;
	}
}

void		ft_sort(t_cube *cube)
{
	while (cube->i < cube->nb_sprite)
	{
		cube->sprites.dist =
		((cube->posx - cube->sprites.posx) *
		(cube->posx - cube->sprites.posx) +
		(cube->posy - cube->sprites.posy) *
		(cube->posy - cube->sprites.posy));
		cube->i++;
	}
	cube->i = 1;
	ft_sort_two(cube);
}

void		ft_raycasting_sprite_two(t_cube *cube)
{
	cube->tramy = cube->inv_det * ((-cube->planey * cube->sprite.x) +
					(cube->planex * cube->sprite.y));
	cube->sp_x = (int)(cube->pars.screenwidth / 2) *
					(1 + cube->tramx / cube->tramy);
	cube->sp_h = abs((int)(cube->pars.screenheight / (cube->tramy)));
	cube->draw_start_y = ((-cube->sp_h / 2) + (cube->pars.screenheight / 2));
	if (cube->draw_start_y < 0)
		cube->draw_start_y = 0;
	cube->draw_end_y = (cube->sp_h / 2 + cube->pars.screenheight / 2);
	if (cube->draw_end_y >= cube->pars.screenheight)
		cube->draw_end_y = cube->pars.screenheight - 1;
	cube->sp_w = abs((int)(cube->pars.screenheight / (cube->tramy)));
	cube->draw_start_x = -cube->sp_w / 2 + cube->sp_x;
	if (cube->draw_start_x < 0)
		cube->draw_start_x = 0;
	cube->draw_end_x = cube->sp_w / 2 + cube->sp_x;
	if (cube->draw_end_x >= cube->pars.screenwidth)
		cube->draw_end_x = cube->pars.screenwidth - 1;
	cube->stripe = cube->draw_start_x;
}

void		ft_raycasting_sprite(t_cube *cube)
{
	int i;

	i = 0;
	ft_sort(cube);
	while (i < cube->nb_sprite)
	{
		cube->sprite.x = cube->sprites.posx - cube->posx;
		cube->sprite.y = cube->sprites.posy - cube->posy;
		cube->inv_det = 1.0 / ((cube->planex * cube->diry) -
						(cube->dirx * cube->planey));
		cube->tramx = cube->inv_det * ((cube->diry * cube->sprite.x) -
						(cube->dirx * cube->sprite.y));
		ft_raycasting_sprite_two(cube);
		while (cube->stripe < cube->draw_end_x)
		{
			cube->tex_x = (int)((256 * (cube->stripe -
						(-cube->sp_w / 2 + cube->sp_x))
				* cube->text_spr.width / cube->sp_w) / 256);
			if (cube->tramy > 0 && cube->stripe > 0 && cube->stripe <
			cube->pars.screenwidth && cube->tramy < cube->zbuffer[cube->stripe])
				ft_draw_sprite(cube);
			cube->stripe++;
		}
		i++;
	}
}
