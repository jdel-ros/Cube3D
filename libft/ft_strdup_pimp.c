/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_pimp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:21:10 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/11 11:10:06 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_pimp(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	if (!(dup = (char*)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\n';
	dup[i + 1] = '\0';
	return (dup);
}
