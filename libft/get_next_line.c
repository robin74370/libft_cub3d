/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: repinat <repinat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:07:58 by repinat           #+#    #+#             */
/*   Updated: 2023/02/13 15:51:53 by repinat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free_line(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	new = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!new)
		return (0);
	j = 0;
	i++;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free(str);
	return (new);
}

char	*ft_put_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_line(char *line, int fd)
{
	char	*buffer;
	int		ret;

	ret = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (!ft_strchr(line, '\n') && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[ret] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (0);
	str[fd] = ft_read_line(str[fd], fd);
	if (!str[fd])
		return (0);
	line = ft_put_line(str[fd]);
	str[fd] = ft_free_line(str[fd]);
	return (line);
}
