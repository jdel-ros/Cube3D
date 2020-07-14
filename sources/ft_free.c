/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:53:46 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/06/10 12:13:58 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void		ft_free(t_cube *cube)
{
	int i;

	i = 0;
	if (cube->pars.texture_n != NULL)
		free(cube->pars.texture_n);
	if (cube->pars.texture_s != NULL)
		free(cube->pars.texture_s);
	if (cube->pars.texture_e != NULL)
		free(cube->pars.texture_e);
	if (cube->pars.texture_w != NULL)
		free(cube->pars.texture_w);
	if (cube->pars.texture_sprite != NULL)
		free(cube->pars.texture_sprite);
	free(cube->zbuffer);
	while (i < cube->pars.height)
	{
		free(cube->map_temp[i]);
		i++;
	}
	free(cube->map_temp);
}
