/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquincy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 01:50:36 by jquincy           #+#    #+#             */
/*   Updated: 2019/11/21 14:17:28 by jquincy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
# define FT_NLONG_MAX	((unsigned long)(~0L))
# define FT_LONG_MAX	((long)(FT_NLONG_MAX >> 1))
# define FT_LONG_MIN	((long)(~FT_LONG_MAX))
# define FT_NINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_NINT_MAX >> 1))
# define FT_INT_MIN		((int)(~FT_INT_MAX))

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

long long			ft_abs(long long nbr);

void				ft_bzero(void *s, size_t n);

int					ft_isalpha(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isdigit(int c);

int					ft_isprint(int c);

int					ft_isspace(char c);

void				*ft_memalloc(size_t size);

void				*ft_memchr(const void *s, int c, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				ft_memdel(void **ap);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memset(void *b, int c, size_t len);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

void				ft_putstr(char const *s);

void				ft_putstr_fd(char const *s, int fd);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strrchr(const char *s, int c);

char				*ft_strchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);

char				*ft_strcpy(char *dst, const char *src);

void				ft_strdel(char **as);

char				*ft_strdup(const char *s1);

int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlen(const char *s);

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strncat(char *dest, const char *src, size_t n);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strncpy(char *dst, const char *src, size_t len);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strnew(size_t size);

char				*ft_strnstr(const char *hs, const char *ndl, size_t len);

char				*ft_strstr(const char *hs, const char *ndl);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					ft_tolower(int c);

int					ft_toupper(int c);

int					ft_atoi(const char *str);

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

char				*ft_strtrim(char const *s);

char				*ft_itoa(int n);

int					ft_isblank(int c);

char				**ft_strsplit(char const *s, char c);

void				ft_strclr(char *s);

int					ft_isspace(char c);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstrev(t_list **alst);

t_list				*ft_lstnew(void const *content, size_t content_size);

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

size_t				ft_lstcount(t_list *lst);

#endif
