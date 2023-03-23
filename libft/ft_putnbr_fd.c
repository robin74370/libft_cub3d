/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:20:06 by repinat           #+#    #+#             */
/*   Updated: 2021/11/26 12:11:06 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	nb;
	int		tab[10];

	i = 0;
	nb = n;
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 0)
	{
		nb *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (nb > 0)
	{
		tab[i] = nb % 10 + '0';
		nb /= 10;
		i++;
	}
	while (--i >= 0)
		write(fd, &tab[i], 1);
}