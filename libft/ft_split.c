/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:09:12 by repinat           #+#    #+#             */
/*   Updated: 2021/11/30 16:52:11 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		count++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	*ft_strdupmodif(const char *str, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i])
		i++;
	tab = malloc((i + 1) * sizeof(char));
	if (!tab)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		len;
	char	**tab;

	if (!str)
		return (0);
	len = ft_count(str, c);
	tab = malloc((len + 1) * sizeof(char *));
	if (!tab)
		return (0);
	j = 0;
	i = 0;
	while (j < len && str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		tab[j] = ft_strdupmodif(&str[i], c);
		j++;
		while (str[i] && str[i] != c)
			i++;
	}
	tab[j] = 0;
	return (tab);
}
