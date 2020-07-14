/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:19:52 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/12 19:28:17 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cubeddd.h"

int				ft_puterror(t_cube *cube, char *str)
{
	cube->error = 1;
	ft_putstr(str);
	return (0);
}

int				ft_puterror_two(t_cube *cube, char *str)
{
	cube->error_two = 1;
	ft_putstr(str);
	return (0);
}
