/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:37:00 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 13:02:43 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_conv_map(t_cube *cube)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!(cube->worldmap = (int**)malloc(sizeof(int*) * cube->pars.height)))
		return (0);
	while (cube->map_temp[x])
	{
		if (!(cube->worldmap[x] = malloc(sizeof(int*) * cube->pars.width_map)))
			return (0);
		while (y < cube->pars.width_map)
		{
			cube->worldmap[x][y] = ft_atoi_char(cube->map_temp[x][y]);
			y++;
			if (cube->map_temp[x][y] == '\0' && y < cube->pars.width_map)
			{
				while (y <= cube->pars.width_map)
					cube->worldmap[x][y++] = 1;
			}
		}
		y = 0;
		x++;
	}
	return (0);
}

int				ft_parsing_choose(t_cube *cube, char *line)
{
	if (cube->pars.width != 0)
	{
		cube->pars.temp = ft_strdup(cube->pars.str);
		cube->pars.str = ft_strjoin(cube->pars.temp, line);
		cube->pars.twidth = ft_strlen(line);
	}
	if (cube->pars.width == 0)
	{
		cube->pars.str = ft_strdup(line);
		cube->pars.width = ft_strlen(line);
		cube->pars.twidth = cube->pars.width;
	}
	return (0);
}

int				ft_parsing_map_three(t_cube *cube)
{
	int x;

	x = 0;
	cube->pars.height = 0;
	ft_check_map_char(cube->pars.str);
	cube->map_temp = ft_split(cube->pars.str, '\n');
	while (cube->map_temp[x])
	{
		cube->pars.height++;
		x++;
	}
	x = 0;
	if (ft_check_map(cube) == 0)
		return (0);
	ft_fill_map(cube);
	ft_conv_map(cube);
	ft_read_map(cube);
	ft_recover_sprite(cube);
	return (0);
}

void			ft_parsing_map_two(t_cube *cube, int count, char *line)
{
	if (line[0] != '1' && count == 1)
		free(line);
	else
	{
		if ((int)ft_strlen(line) > cube->pars.width_map)
			cube->pars.width_map = ft_strlen(line);
		cube->pars.temp_two = ft_strdup_pimp(line);
		free(line);
		line = ft_strdup(cube->pars.temp_two);
		free(cube->pars.temp_two);
		cube->pars.temp = ft_strdup(line);
		free(line);
		line = ft_strdup(cube->pars.temp);
		free(cube->pars.temp);
		ft_parsing_choose(cube, line);
		free(line);
	}
}

int				ft_parsing(t_cube *cube, char *str)
{
	int		fd;
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (cube->error == 1)
			return (0);
		if (cube->pars.perm != 8)
			ft_parsing_start(line, cube);
		else if (cube->pars.perm == 8)
		{
			count++;
			ft_parsing_map_two(cube, count, line);
		}
	}
	return (ft_parsing_map_three(cube));
}
