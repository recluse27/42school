/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:49:17 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/11 09:49:19 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

#endif
