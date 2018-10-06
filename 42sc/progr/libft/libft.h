/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:49:17 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/12 20:26:45 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next	
}					t_list
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

int		ft_isspace(char c);
char	*ft_strtrim(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strnew(size_t size);



#endif
