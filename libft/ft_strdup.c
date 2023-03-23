/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <repinat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:11:27 by repinat           #+#    #+#             */
/*   Updated: 2023/02/13 15:24:48 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int				i;
	int				len;
	unsigned char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
	{
		free(dup);
		return (0);
	}
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return ((char *)(dup));
}
