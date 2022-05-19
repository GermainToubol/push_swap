/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:21:12 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/10 12:10:54 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FDS
#  define MAX_FDS 25
# endif

typedef struct s_buffer
{
	int		fd;
	size_t	size;
	char	buffer[BUFFER_SIZE];
}	t_buffer;

char		*get_next_line(int fd);
t_buffer	*get_buffer(int fd, t_buffer *buffers);
size_t		gnl_nl_place(char *str, size_t size);
char		*gnl_read_to_newline(int fd, t_buffer *buffer, size_t *size);
size_t		gnl_join(char **dest, size_t size_d, char *src, size_t size_s);
char		*gnl_update_newline_buffer(
				char *src,
				size_t size,
				t_buffer *buffer);
#endif
