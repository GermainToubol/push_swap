/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtoubol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:03:43 by gtoubol           #+#    #+#             */
/*   Updated: 2022/05/16 16:38:51 by gtoubol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

/* Vanilla libft */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *s2, size_t len);
int			ft_atoi(const char *s);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Get_next_line integration */

# define BUFFER_SIZE 42
# define MAX_FDS 2

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

/* ft_printf integration */

typedef struct s_convert
{
	char	convertion;
	char	alternate;
	char	padd_char;
	char	leftify;
	int		padd_size;
	int		has_precision;
	int		precision;
	char	sign;

}	t_convert;

int			ft_printf(const char *format, ...);

int			ft_printf_char(char c, t_convert *convert);
int			ft_printf_str(char *str, t_convert *convert);

int			ft_printf_long_hex(unsigned long int nbr,
				char *charset,
				t_convert *convert);
int			ft_printf_ptr(void	*ptr, t_convert *convert);

int			ft_printf_int(int n, t_convert *convert);
int			ft_printf_unsigned(unsigned int nbr, t_convert *convert);

int			ft_printf_hex_base(unsigned int nbr, char *charset,
				t_convert *convert);
int			ft_printf_hex(unsigned int nbr, t_convert *convert);
int			ft_printf_hex_caps(unsigned int nbr, t_convert *convert);

int			ft_printf_percent(void);

int			ft_printf_padding(int len, t_convert *convert);
int			ft_atoi_padding(char *format, t_convert *convert);

int			ft_printf_precision(t_convert *convert);
int			ft_len_precision(int len, t_convert *convert);
int			ft_atoi_precision(char *format, t_convert *convert);

int			set_arguments(char *format, t_convert *convert);

#endif
