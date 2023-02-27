/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anais <anais@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:16:20 by henkaoua          #+#    #+#             */
/*   Updated: 2023/02/05 12:52:29 by anais            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef unsigned long int	t_size;
int		ft_isalnum(int c);
void	*ft_calloc(t_size count, t_size size);
void	ft_bzero(void *ptr, t_size num);
int		ft_atoi(const char *str);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
void	*ft_memcpy(void *pdst, const void *psrc, unsigned long int n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
void	*ft_memchr(const void *s, int c, t_size n);
char	*ft_itoa(int n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_memset(void *str, int c, t_size num);
void	*ft_memmove(void *pdst, const void *psrc, unsigned long int n);
char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_size	ft_strlcat(char *dst, const char *src, t_size n);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *cpy);
int		ft_strncmp(const char *s1, const char *s2, t_size n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strlen(const char *str);
t_size	ft_strlcpy(char *dst, const char *src, t_size dlen);
char	*ft_substr(const char *s, unsigned int start, t_size len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, t_size len);
int		ft_toupper(int c);
int		ft_tolower(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
char	*get_next_line(int fd);
char	*get_next_line_free(int fd, char *line);
int		ft_is_space(char c);
int		check_c(char c);
#endif
