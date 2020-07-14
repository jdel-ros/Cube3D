/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdel-ros <jdel-ros@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:14:12 by jdel-ros          #+#    #+#             */
/*   Updated: 2020/03/11 11:45:27 by jdel-ros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long int	i;
	const unsigned char	*str2;
	const unsigned char	*str1;

	i = 0;
	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && i < n - 1 && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int		ft_strncmp_pimp(const char *s1, const char *s2, size_t i)
{
	const unsigned char	*str2;
	const unsigned char	*str1;
	size_t				j;

	j = 0;
	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	while (str1[i] && str2[j] && str1[i] == str2[j])
	{
		i++;
		j++;
	}
	return (str1[i] - str2[j]);
}
