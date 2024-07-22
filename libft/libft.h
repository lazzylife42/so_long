/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:58:34 by smonte-e          #+#    #+#             */
/*   Updated: 2023/10/09 15:51:28 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//  libft 

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strndup(char *buff, size_t end);
char	*ft_free_null(char *buff);

//  ft_printf

int		ft_printf(const char *format, ...);
int		ft_printf_ui(unsigned long long number);
int		ft_printf_conv(char format, va_list ap);
int		ft_printf_char(char c);
int		ft_printf_str(char *str);
int		ft_printf_n_base(long long number, char *base);
int		ft_printf_ptr(unsigned long ptr);
char	*ft_ulltoa_base(unsigned long long number, char *base);

//  linked_list

typedef struct t_Cell
{
	int				data;
	struct t_Cell	*next;
}t_List,	t_Cell;

t_Cell	*create_cell(int data);
void	set_at(t_List *list, int data, int pos);
void	print_list(t_List *list);
int		is_emplty_list(t_List *list);
int		get_at(t_List *list, int pos);
long	len_list(t_List *list);
t_List	*empty_list(void);
t_List	*add_at(t_List *list, int data, int pos);
t_List	*add_end(t_List *list, int data);
t_List	*free_at(t_List *list, int pos);
t_List	*free_list(t_List *list);

//	get_next_line

char	*get_next_line(int fd);
char	*gnl_remove_old_line(char *buff);
char	*gnl_get_line(char *buff);
char	*ft_strndup(char *buff, size_t end);
char	*gnl_read(int fd, char *res);
char	*ft_gnl_strjoin(char *line, char *buff);
void	*ft_calloc(size_t nb_elem, size_t size_elem);
char	*ft_free_null(char *buff);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
ssize_t	find_newline_index(char *buff);

#endif
