/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:36 by repinat           #+#    #+#             */
/*   Updated: 2021/12/01 12:35:42 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	tab = malloc((nmemb * size));
	if (!tab)
		return (0);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
