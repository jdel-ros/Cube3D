/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:46:04 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 17:50:09 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "../includes/cubeddd.h"

int			ft_holdinput(int key, t_cube *cube)
{
	if (key == KEY_ESCAPE)
		ft_exit_hook(cube);
	if (key == KEY_LEFT)
		cube->keys.leftarrow = 1;
	else if (key == KEY_RIGHT)
		cube->keys.rightarrow = 1;
	if (key == KEY_W)
		cube->keys.w = 1;
	if (key == KEY_A)
		cube->keys.a = 1;
	if (key == KEY_S)
		cube->keys.s = 1;
	if (key == KEY_D)
		cube->keys.d = 1;
	if (key == KEY_SHIFT_LEFT)
		cube->movespeed *= 2;
	return (0);
}

int			ft_releaseinput(int key, t_cube *cube)
{
	if (key == KEY_ESCAPE)
		ft_exit_hook(cube);
	if (key == KEY_LEFT)
		cube->keys.leftarrow = 0;
	else if (key == KEY_RIGHT)
		cube->keys.rightarrow = 0;
	if (key == KEY_W)
		cube->keys.w = 0;
	if (key == KEY_A)
		cube->keys.a = 0;
	if (key == KEY_S)
		cube->keys.s = 0;
	if (key == KEY_D)
		cube->keys.d = 0;
	if (key == KEY_SHIFT_LEFT)
		cube->movespeed /= 2;
	return (0);
}

int			ft_exit_hook(t_cube *cube)
{
	mlx_clear_window(cube->mlx, cube->window);
	mlx_destroy_window(cube->mlx, cube->window);
	ft_free(cube);
	exit(0);
}

int			deal_key(t_cube *cube)
{
	t_vector futur_move;

	if (cube->keys.w == 1)
		ft_move_up_front(cube, &futur_move);
	if (cube->keys.s == 1)
		ft_move_up_down(cube, &futur_move);
	if (cube->keys.d == 1)
		ft_move_up_right(cube, &futur_move);
	if (cube->keys.a == 1)
		ft_move_up_left(cube, &futur_move);
	if (cube->keys.leftarrow)
		ft_dir_up_left(cube);
	if (cube->keys.rightarrow)
		ft_dir_up_right(cube);
	ft_collision(cube, futur_move);
	cube->posx = cube->posx + futur_move.x * cube->perm.x;
	cube->posy = cube->posy + futur_move.y * cube->perm.y;
	ft_print_ray(cube);
	return (1);
}
