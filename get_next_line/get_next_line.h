/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolonne <acolonne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:36:10 by acolonne          #+#    #+#             */
/*   Updated: 2025/02/03 19:01:51 by acolonne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stdlib.h>
# include <unistd.h>

char	*build_line(char *buf);

char	*buffer_remainder(char *buf);

char	*read_file(char *buf, int fd);

char	*get_next_line(int fd, int ext);

int		ft_strlen(char *s);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char *s1, char *s2);

void	ft_bzero(void *s, size_t n);

#endif
