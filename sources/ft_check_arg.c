/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:45:22 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 15:22:11 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int			ft_check_arg_map(t_cube *cube, char *map)
{
	char		*str;
	int			i;

	i = 0;
	str = ft_strdup(map);
	while (str[i] != '.' && str[i])
		i++;
	if (str[i] == '\0')
		return (ft_puterror(cube, "Erreur extension map1\n"));
	if (ft_strncmp_pimp(str, ".cub", i) == 0)
	{
		free(str);
		return (1);
	}
	else
	{
		free(str);
		return (ft_puterror(cube, "Erreur extension map2\n"));
	}
}

int			ft_check_arg_save(t_cube *cube, char *save)
{
	char		*str;
	int			i;

	i = 0;
	str = ft_strdup(save);
	if (str[i] == '\0')
		return (ft_puterror(cube, "Erreur --save\n"));
	if (ft_strncmp_pimp(str, "--save", i) == 0)
	{
		free(str);
		cube->perm_save = 1;
		return (1);
	}
	else
	{
		free(str);
		return (ft_puterror(cube, "Erreur --save\n"));
	}
}
