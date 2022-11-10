/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:15:35 by takonaga          #+#    #+#             */
/*   Updated: 2022/11/11 00:49:24 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int8_t	*ft_read_to_left_str(int32_t fd, int8_t *left_str)
{
	int8_t	*buff;
	ssize_t	rd_bytes;

	buff = malloc((BUFFER_SIZE + 1ul) * sizeof(int8_t));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
		if (!left_str)
		{
			free(buff);
			return (NULL);
		}
	}
	free(buff);
	return (left_str);
}

int8_t	*ft_get_line(int8_t *left_str)
{
	size_t		i;
	int8_t		*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (int8_t *)malloc(sizeof(int8_t) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int8_t	*ft_new_left_str(int8_t *left_str)
{
	size_t	i;
	size_t	j;
	int8_t	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (int8_t *)malloc(sizeof(int8_t) * (ft_strlen(left_str) - i + 1));
	if (!str)
	{
		free(left_str);
		return (NULL);
	}
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*get_next_line(int fd)
{
	int8_t			*line;
	static int8_t	*left_str[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (NULL);
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]);
	if (!left_str[fd])
		return (NULL);
	line = ft_get_line(left_str[fd]);
	left_str[fd] = ft_new_left_str(left_str[fd]);
	return ((char *)line);
}
