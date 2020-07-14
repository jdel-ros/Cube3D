/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:18:53 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/16 16:32:59 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_parsing_start(char *s, t_cube *cube)
{
	if (ft_strncmp(s, "R ", 2) == 0)
		return (ft_parsing_resolution(s, cube));
	else if (ft_strncmp(s, "F ", 2) == 0 || ft_strncmp(s, "C ", 2) == 0)
		return (ft_parsing_ground_sky(s, cube));
	else if (ft_strncmp(s, "NO ", 2) == 0)
		cube->pars.texture_n = ft_parsing_texture(s, cube);
	else if (ft_strncmp(s, "SO ", 2) == 0)
		cube->pars.texture_s = ft_parsing_texture(s, cube);
	else if (ft_strncmp(s, "EA ", 2) == 0)
		cube->pars.texture_e = ft_parsing_texture(s, cube);
	else if (ft_strncmp(s, "WE ", 2) == 0)
		cube->pars.texture_w = ft_parsing_texture(s, cube);
	else if (ft_strncmp(s, "S ", 1) == 0)
		cube->pars.texture_sprite = ft_parsing_texture(s, cube);
	return (0);
}

int				ft_parsing_resolution(char *s, t_cube *cube)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	j = 0;
	if (!(cube->pars.width_str = (char *)malloc(sizeof(char) * 4)))
		return (0);
	if (!(cube->pars.height_str = (char *)malloc(sizeof(char) * 4)))
		return (0);
	str = ft_strdup(s);
	while (str[i] == ' ')
		i++;
	while ((ft_isdigit(str[i]) == 1) && str[i] != ' ')
	{
		cube->pars.width_str[j] = str[i];
		i++;
		j++;
	}
	j = 0;
	while (str[i] == ' ')
		i++;
	return (ft_resolution_two(str, cube, i, j));
}

int				ft_resolution_two(char *str, t_cube *cube, int i, int j)
{
	while ((ft_isdigit(str[i]) == 1) && str[i] != ' ')
	{
		cube->pars.height_str[j] = str[i];
		i++;
		j++;
		if (str[i] == '\0')
		{
			cube->pars.screenwidth = ft_atoi(cube->pars.width_str);
			cube->pars.screenheight = ft_atoi(cube->pars.height_str);
			free(str);
			free(cube->pars.width_str);
			free(cube->pars.height_str);
			cube->pars.perm++;
			return (0);
		}
	}
	ft_puterror(cube, "Error Resolution\n");
	free(cube->pars.width_str);
	free(cube->pars.height_str);
	free(str);
	return (0);
}

int				ft_parsing_ground_sky(char *s, t_cube *cube)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup(s);
	while (str[i] == ' ' && str[i])
		i++;
	if (str[0] == 'F')
		cube->pars.ground_r = ft_atoi_pimp(str, i);
	if (str[0] == 'C')
		cube->pars.sky_r = ft_atoi_pimp(str, i);
	while ((ft_isdigit(str[i]) == 1) && str[i] != ',' && str[i])
		i++;
	if (str[i] == ',')
		i++;
	if (str[0] == 'F')
		cube->pars.ground_g = ft_atoi_pimp(str, i);
	if (str[0] == 'C')
		cube->pars.sky_g = ft_atoi_pimp(str, i);
	while ((ft_isdigit(str[i]) == 1) && str[i] != ',' && str[i])
		i++;
	return (ft_parsing_ground_sky_two(str, i, cube));
}

int				ft_parsing_ground_sky_two(char *str, int i, t_cube *cube)
{
	if (str[i] == ',')
		i++;
	if (str[0] == 'F')
		cube->pars.ground_b = ft_atoi_pimp(str, i);
	if (str[0] == 'C')
		cube->pars.sky_b = ft_atoi_pimp(str, i);
	while ((ft_isdigit(str[i]) == 1) && str[i] != '\0')
	{
		i++;
		if (str[i] == '\0')
		{
			free(str);
			cube->pars.perm++;
			return (0);
		}
	}
	ft_puterror(cube, "Error Colors\n");
	free(str);
	return (0);
}
