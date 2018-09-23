/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:15:06 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/20 12:27:51 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_abs(int nb);
int		ft_strlen(char *str);
char	*ft_itoa(long long value, int base);
int		b_printf(const char *format, ...);
int		conv_set(const char c, va_list arg);
int		cnv_s(va_list arg);
int		cnv_c(va_list arg);
int		cnv_int(va_list arg);
int		cnv_p(va_list arg);
int		cnv_o(va_list arg);
int		cnv_u(va_list arg);
int		cnv_x(va_list arg);
int		cnv_prc(va_list arg);

#endif
