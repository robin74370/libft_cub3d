/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:01:23 by repinat           #+#    #+#             */
/*   Updated: 2021/11/26 15:28:48 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	n2;

	if (n == 0)
		return (0);
	n2 = (unsigned int)n;
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n2 - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
