/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 22:38:17 by takonaga          #+#    #+#             */
/*   Updated: 2022/11/10 21:28:18 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
int8_t	*ft_read_to_left_str(int32_t fd, int8_t *left_str);
size_t	ft_strlen(int8_t *s);
int8_t	*ft_strchr(int8_t *s, int32_t c);
int8_t	*ft_strjoin(int8_t *left_str, int8_t *buff);
int8_t	*ft_get_line(int8_t *left_str);
int8_t	*ft_new_left_str(int8_t *left_str);

#endif
