/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_for.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:55:45 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 15:42:00 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_fill_map_two(t_cube *cube, int x, int y)
{
	while (cube->map_temp[x])
	{
		if (cube->map_temp[x][y] == ' ')
			cube->map_temp[x][y] = '1';
		if (cube->map_temp[x][(int)ft_strlen(cube->map_temp[x]) - 1] == ' ')
			cube->map_temp[x][(int)ft_strlen(cube->map_temp[x]) - 1] = '1';
		x++;
	}
	x = 0;
	y = 0;
	while (cube->map_temp[x])
	{
		while (cube->map_temp[x][y])
		{
			if (cube->map_temp[x][y] == ' ')
				cube->map_temp[x][y] = '1';
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int				ft_fill_map(t_cube *cube)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (cube->map_temp[x][y])
	{
		if (cube->map_temp[x][y] == ' ')
			cube->map_temp[x][y] = '1';
		y++;
	}
	x = cube->pars.height - 1;
	y = 0;
	while (cube->map_temp[x][y])
	{
		if (cube->map_temp[x][y] == ' ')
			cube->map_temp[x][y] = '1';
		y++;
	}
	x = 0;
	y = 0;
	return (ft_fill_map_two(cube, x, y));
}

void			ft_recover_sprite(t_cube *cube)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (x < cube->pars.height)
	{
		while (y < cube->pars.width_map)
		{
			if (cube->worldmap[x][y] == 2)
				cube->nb_sprite++;
			y++;
		}
		x++;
		y = 0;
	}
	if (cube->nb_sprite > 1)
	{
		ft_puterror(cube, "1 sprite maximum, déso\n");
		return ;
	}
	ft_recover_sprite_two(cube, x, y, i);
}

void			ft_recover_sprite_two(t_cube *cube, int x, int y, int i)
{
	x = 0;
	y = 0;
	while (x < cube->pars.height)
	{
		while (y < cube->pars.width_map)
		{
			if (cube->worldmap[x][y] == 2 && i < cube->nb_sprite)
			{
				cube->sprites.posx = x + 0.5;
				cube->sprites.posy = y + 0.5;
				i++;
			}
			y++;
		}
		x++;
		y = 0;
	}
}

int				ft_check_line(t_cube *cube, char *line)
{
	int i;

	(void)cube;
	i = -1;
	while (i < 201)
	{
		i++;
		if (line[i] == '\0')
			return (0);
		if (line[i] == '1' || line[i] == '0')
			return (1);
	}
	return (0);
}
