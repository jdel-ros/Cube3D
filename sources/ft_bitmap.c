/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:01:06 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/07/13 16:39:45 by juan             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

void			ft_bitmap_image(t_cube *cube, int fd)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	y = cube->pars.screenheight - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cube->pars.screenwidth)
		{
			ble = cube->img.data[x + y * cube->pars.screenwidth];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

int				ft_save_bitmap(const char *filename, t_cube *cube)
{
	ft_memcpy(&cube->bfh.bitmap_type, "BM", 2);
	cube->bfh.file_size = cube->pars.screenwidth *
							cube->pars.screenheight * 4 + 54;
	cube->bfh.reserved1 = 0;
	cube->bfh.reserved2 = 0;
	cube->bfh.offset_bits = 0;
	cube->bih.size_header = sizeof(cube->bih);
	cube->bih.width = cube->pars.screenwidth;
	cube->bih.height = cube->pars.screenheight;
	cube->bih.planes = 1;
	cube->bih.bit_count = 24;
	cube->bih.compression = 0;
	cube->bih.image_size = cube->pars.screenwidth *
							cube->pars.screenheight * 4 + 54;
	cube->bih.ppm_x = 2;
	cube->bih.ppm_y = 2;
	cube->bih.clr_used = 0;
	cube->bih.clr_important = 0;
	cube->fd = open(filename, O_RDWR | O_CREAT, 0777);
	write(cube->fd, &cube->bfh, 14);
	write(cube->fd, &cube->bih, sizeof(cube->bih));
	ft_bitmap_image(cube, cube->fd);
	close(cube->fd);
	return (0);
}
