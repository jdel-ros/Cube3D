/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:53:26 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/10 16:34:43 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int			ft_move_up_front(t_cube *cube, t_vector *futur_move)
{
	futur_move->x += cube->dirx * cube->movespeed;
	futur_move->y += cube->diry * cube->movespeed;
	return (0);
}

int			ft_move_up_down(t_cube *cube, t_vector *futur_move)
{
	futur_move->x -= cube->dirx * cube->movespeed;
	futur_move->y -= cube->diry * cube->movespeed;
	return (0);
}

int			ft_move_up_right(t_cube *cube, t_vector *futur_move)
{
	futur_move->x += cube->planex * cube->movespeed;
	futur_move->y += cube->planey * cube->movespeed;
	return (0);
}

int			ft_move_up_left(t_cube *cube, t_vector *futur_move)
{
	futur_move->x -= cube->planex * cube->movespeed;
	futur_move->y -= cube->planey * cube->movespeed;
	return (0);
}
