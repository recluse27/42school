/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:29:41 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:29:49 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H
# define SAVE_THE_WORLD "savior"
# include <string.h>

typedef struct	s_perso
{
	char	*name;
	float	life;
	int		age;
	char	*profession;
}				t_perso;

#endif
