/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:54:56 by relkabou          #+#    #+#             */
/*   Updated: 2022/10/18 18:59:56 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>

/* ============================== Part 1 ============================== */
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strrchr(char *s, int c);
int		ft_atoi(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_memcmp(void *s1, void *s2, size_t n);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	**ft_split(char *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ============================== Printf ============================== */
typedef struct s_printf_params
{
	int		fd;
	char	form;
	int		ret;
	int		err;
}   t_printf_params;

void	ft_putc(char c, t_printf_params *p);
void	ft_puts(char *s, t_printf_params *p);
void	ft_putn(long nbr, t_printf_params *p);
void	ft_putx(unsigned long nbr, t_printf_params *p);
void	ft_putp(void *nbr, t_printf_params *p);
int     ft_fprintf(int fd, char *s, ...);

/* ============================= Get next line ============================= */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif // BUFFER_SIZE

# define MAX_FD 10420

void	free_ptr(char **ptr);
char	*read_line(int fd, char **buffer, char *read_return);
char	*get_next_line(int fd);
char	*merge_line(int nl_position, char **buffer);

/* ============================== Linked Lists ============================== */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
