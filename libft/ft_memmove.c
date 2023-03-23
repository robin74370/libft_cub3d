/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:38:03 by repinat           #+#    #+#             */
/*   Updated: 2021/11/29 16:55:40 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest1;
	unsigned char	*src1;
	size_t			i;

	if (!dst || !src)
		return (0);
	dest1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = -1;
	if (dest1 > src1)
	{
		while (len > 0)
		{
			dest1[len - 1] = src1[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
			dest1[i] = src1[i];
	}
	return (dest1);
}
