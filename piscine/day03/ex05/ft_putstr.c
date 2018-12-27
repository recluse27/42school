/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 22:54:49 by vlazuka           #+#    #+#             */
/*   Updated: 2018/07/27 23:21:22 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int counter;

	counter = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[counter]);
		counter++;
	}
}
