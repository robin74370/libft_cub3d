/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:56:38 by repinat           #+#    #+#             */
/*   Updated: 2021/12/01 15:09:51 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		count;

	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (ft_isinset(s1[j], set))
		j--;
	j++;
	if (i == ft_strlen(s1))
		return (0);
	count = j - i;
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		i;
	int		j;
	int		k;
	int		l;

	if (!s1)
		return (0);
	trim = malloc((ft_count(s1, set) + 1) * sizeof(char));
	if (!trim)
		return (0);
	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	k = i - 1;
	j = ft_strlen(s1) - 1;
	while (ft_isinset(s1[j], set))
		j--;
	l = 0;
	while (++k <= j)
		trim[l++] = s1[k];
	trim[l] = '\0';
	return (trim);
}
