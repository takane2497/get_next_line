/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:41:59 by takonaga          #+#    #+#             */
/*   Updated: 2022/11/11 00:35:32 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(int8_t *s);
int8_t	*ft_read_to_left_str(int32_t fd, int8_t *left_str);
int8_t	*ft_strchr(int8_t *s, int32_t c);
int8_t	*ft_strjoin(int8_t *left_str, int8_t *buff);
int8_t	*ft_get_line(int8_t *left_str);
int8_t	*ft_new_left_str(int8_t *left_str);

#endif
