/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:32:09 by repinat           #+#    #+#             */
/*   Updated: 2021/11/30 16:39:11 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
		{
			sub[i] = s[j];
			i++;
		}
		j++;
	}
	sub[i] = '\0';
	return (sub);
}
