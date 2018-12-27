/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 16:30:09 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/03 16:30:15 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H

# define OPEN 1
# define CLOSE 0
# define EXIT_SUCCESS 0

# include <unistd.h>

typedef int		t_bool;

typedef struct	s_door
{
	t_bool	state;
}				t_door;

#endif
