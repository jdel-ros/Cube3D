/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:52:05 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/16 16:31:52 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_check_colors(t_cube *cube, int colors)
{
	if (colors > 255)
	{
		colors = 255;
		cube->error_parsing = 1;
		return (colors);
	}
	if (colors < 0)
	{
		colors = 0;
		cube->error_parsing = 1;
		return (colors);
	}
	return (colors);
}

int				ft_check_parsing(t_cube *cube)
{
	cube->pars.ground_r = ft_check_colors(cube, cube->pars.ground_r);
	cube->pars.ground_g = ft_check_colors(cube, cube->pars.ground_g);
	cube->pars.ground_b = ft_check_colors(cube, cube->pars.ground_b);
	if (cube->error_parsing == 1)
		ft_putstr("Color ground automatically set to 0/255\n");
	cube->error_parsing = 0;
	cube->pars.sky_r = ft_check_colors(cube, cube->pars.sky_r);
	cube->pars.sky_g = ft_check_colors(cube, cube->pars.sky_g);
	cube->pars.sky_b = ft_check_colors(cube, cube->pars.sky_b);
	if (cube->error_parsing == 1)
		ft_putstr("Color sky automatically set to 0/255\n");
	if (cube->pars.screenwidth > 2560)
	{
		cube->pars.screenwidth = 2560;
		ft_putstr("ScreenWidth automatically set to 2560\n");
	}
	if (cube->pars.screenheight > 1440)
	{
		cube->pars.screenheight = 1440;
		ft_putstr("ScreenHeight automatically set to 1440\n");
	}
	return (0);
}

int				ft_check_map(t_cube *cube)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (cube->map_temp[x])
	{
		while (cube->map_temp[x][y])
		{
			if (cube->map_temp[x][y] == '0')
			{
				if (ft_check_wall(x, y, cube) == -1)
				{
					ft_puterror(cube, "\n");
					return (0);
				}
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int				ft_check_map_char(char *str)
{
	int i;
	int a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (ft_find(str[i], "WESN012") == 0)
			return (0);
		if (str[i] == 'W' || str[i] == 'E' || str[i] == 'S' || str[i] == 'N')
			a++;
		i++;
	}
	if (a != 1)
		return (0);
	return (1);
}

int				ft_check_wall(int x, int y, t_cube *cube)
{
	cube->a = y;
	while (cube->map_temp[x][cube->a] != '1' && cube->a > 0
			&& cube->map_temp[x][cube->a] != ' ')
		cube->a--;
	if (cube->map_temp[x][cube->a] != '1')
		return (-1);
	cube->a = y;
	while (cube->map_temp[x][cube->a] && cube->map_temp[x][cube->a] != '1'
			&& cube->map_temp[x][cube->a] != ' ')
		cube->a++;
	if (cube->map_temp[x][cube->a] != '1')
		return (-1);
	cube->b = x;
	while (cube->map_temp[cube->b][y] != '1' && cube->b > 0
			&& cube->map_temp[cube->b][y] != ' ')
		cube->b--;
	if (cube->map_temp[cube->b][y] != '1')
		return (-1);
	cube->b = x;
	while (cube->b < cube->pars.height - 1 && cube->map_temp[cube->b][y] != '1'
			&& cube->map_temp[cube->b][y] != ' ')
		cube->b++;
	if (cube->map_temp[cube->b][y] != '1')
		return (-1);
	return (1);
}
