/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:05:05 by repinat           #+#    #+#             */
/*   Updated: 2021/11/30 16:39:05 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	unsigned int	j;

	if (little[0] == '\0')
		return ((char *)(big));
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if ((size_t)j == ft_strlen(little) - 1)
				return ((char *)(&big[i]));
			j++;
		}
		i++;
	}
	return (0);
}
