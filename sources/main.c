/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:52:37 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/14 15:56:08 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void			ft_initvar(t_cube *cube)
{
	cube->error = 0;
	cube->pars.height = 0;
	cube->pars.width = 0;
	cube->pars.twidth = 0;
	cube->pars.x = 0;
	cube->pars.y = 0;
	cube->temps = 0;
	cube->pi = 3.14159265359;
	cube->movespeed = 0.05;
	cube->rotspeed = 0.03;
	cube->pars.perm = 0;
	cube->texture.texturex = 0;
	cube->texture.texturey = 0;
	cube->keys.leftarrow = 0;
	cube->keys.rightarrow = 0;
	cube->keys.w = 0;
	cube->keys.a = 0;
	cube->keys.s = 0;
	cube->keys.d = 0;
	cube->zbuffer = malloc(sizeof(double *) * cube->pars.screenwidth);
}

void			ft_colors(t_cube *cube)
{
	cube->floor_color = cube->pars.ground_r << 16;
	cube->floor_color += cube->pars.ground_g << 8;
	cube->floor_color += cube->pars.ground_b;
	cube->sky_color = cube->pars.sky_r << 16;
	cube->sky_color += cube->pars.sky_g << 8;
	cube->sky_color += cube->pars.sky_b;
}

int				main_two(t_cube *cube, int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (ft_check_arg_map(cube, argv[1]) == 0)
			return (0);
		if (open(argv[1], O_RDONLY) == -1)
		{
			ft_putstr("Fichier introuvable");
			return (0);
		}
	}
	if (argc == 3)
		ft_check_arg_save(cube, argv[2]);
	ft_parsing(cube, argv[1]);
	if (cube->error == 1 || cube->error_two == 1)
		return (0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_cube cube;

	if (main_two(&cube, argc, argv) == 0)
		return (0);
	ft_check_parsing(&cube);
	cube.mlx = mlx_init();
	ft_texture_init(&cube);
	ft_colors(&cube);
	ft_initvar(&cube);
	cube.window = mlx_new_window(cube.mlx, cube.pars.screenwidth,
					cube.pars.screenheight, "Cube3D");
	cube.img.img = mlx_new_image(cube.mlx, cube.pars.screenwidth,
					cube.pars.screenheight);
	cube.img.data = (int *)mlx_get_data_addr(cube.img.img, &cube.img.bpp,
					&cube.img.sline, &cube.img.endian);
	mlx_loop_hook(cube.mlx, deal_key, &cube);
	mlx_hook(cube.window, 2, 0, ft_holdinput, &cube);
	mlx_hook(cube.window, 3, 0, ft_releaseinput, &cube);
	mlx_hook(cube.window, 17, 0, ft_exit_hook, &cube);
	mlx_loop(cube.mlx);
	return (0);
}
