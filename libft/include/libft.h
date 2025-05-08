/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynishimu <ynishimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:57:33 by ynishimu          #+#    #+#             */
/*   Updated: 2023/04/12 19:09:43 by ynishimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "ft_libs.h"
#include "ft_types.h"

//char
///determine
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
///operate
int		ft_toupper(int c);
int		ft_tolower(int c);

//error
void	ft_exit(ssize_t code, void *asnd_0, void *asnd_1, void *asnd_2);

//list
///create
t_list	*ft_lstnew(void *content);
///delete
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
///read
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
///update
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//memory
///allocate
void	*ft_calloc(size_t count, size_t size);
void	*ft_malloc(size_t size, void *asnd_0, void *asnd_1, void *asnd_2);
///measure
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
///operate
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

//string
int		ft_atoi(const char *str);
int		will_overflow(long num, int next);
int		will_underflow(long num, int next);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
size_t	count_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
///copy
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
///measure
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
///modify
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//print
int		ft_vdprintf(int fd, const char *fmt, va_list ap);
int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
///string
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *s, int fd);
///number
ssize_t	ft_putendl_fd(char *s, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
ssize_t	ft_putunbr_fd(unsigned int n, char *digits, int fd);

#endif
