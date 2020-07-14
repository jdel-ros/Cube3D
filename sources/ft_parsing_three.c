/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:59:01 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/12 18:00:29 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void			ft_init_map_two(t_cube *cube, int in_char)
{
	if (in_char == 'S')
	{
		cube->dirx = 1;
		cube->diry = 0;
		cube->planex = 0;
		cube->planey = -0.66;
	}
	else if (in_char == 'N')
	{
		cube->dirx = -1;
		cube->diry = 0;
		cube->planex = 0;
		cube->planey = 0.66;
	}
}

void			ft_init_map(t_cube *cube, int in_char)
{
	if (in_char == 'E')
	{
		cube->dirx = 0;
		cube->diry = 1;
		cube->planex = 0.66;
		cube->planey = 0;
	}
	else if (in_char == 'W')
	{
		cube->dirx = 0;
		cube->diry = -1;
		cube->planex = -0.66;
		cube->planey = 0;
	}
}

int				ft_read_map(t_cube *cube)
{
	int			x;
	int			y;
	int			in_char;

	x = 0;
	y = 0;
	while (x < cube->pars.height)
	{
		while (y < cube->pars.width_map)
		{
			if (cube->worldmap[x][y] + 48 >= 'E')
			{
				in_char = cube->worldmap[x][y] + 48;
				ft_init_map(cube, in_char);
				ft_init_map_two(cube, in_char);
				cube->worldmap[x][y] = 0;
				cube->posx = x + 0.5;
				cube->posy = y + 0.5;
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int				ft_find(const char c, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char			*ft_parsing_texture(char *s, t_cube *cube)
{
	int		i;
	char	*str;
	char	*dest;

	i = 1;
	str = ft_strdup(s);
	while (str[i] != ' ')
		i++;
	i++;
	dest = ft_strcpy_pimp(str, i);
	while (str[i] != '\0' && ft_isascii(str[i]) == 1)
		i++;
	if (str[i] == '\0')
	{
		free(str);
		cube->pars.perm++;
		return (dest);
	}
	ft_puterror(cube, "Error Texture\n");
	free(str);
	return (dest);
}
