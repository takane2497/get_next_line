/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:26:15 by takonaga          #+#    #+#             */
/*   Updated: 2022/11/11 00:51:59 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(int8_t *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int8_t	*ft_strchr(int8_t *s, int32_t c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((int8_t *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (int8_t) c)
			return ((int8_t *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(int8_t *dst, int8_t *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0 ;
	if (dstsize == 0)
		return (src_len);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(int8_t *dst, int8_t *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (dst == NULL)
		return (s_len);
	d_len = ft_strlen(dst);
	if (dstsize <= d_len)
		return (s_len + dstsize);
	ft_strlcpy(&dst[d_len], src, dstsize - d_len);
	return (d_len + s_len);
}

int8_t	*ft_strjoin(int8_t *s1, int8_t *s2)
{
	int8_t	*newstr;
	size_t	len;

	if (!s1)
	{
		s1 = (int8_t *)malloc(1 * sizeof(int8_t));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(int8_t) * (len + 1));
	if (!newstr)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(newstr, s2, len + 1);
	free(s1);
	return (newstr);
}
