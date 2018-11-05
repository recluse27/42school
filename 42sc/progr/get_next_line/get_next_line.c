/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:28:28 by vlazuka           #+#    #+#             */
/*   Updated: 2018/11/04 18:01:36 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int prepare_line(char **s, char **line, int fd)
{
	char	*cursor;
	char	*tmp;
	int		nbr_char;

	cursor = ft_strchr(s[fd], '\n');
	nbr_char = cursor - s[fd];
	if (cursor == 0)
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	else if (cursor)
	{
		*line = ft_strsub(s[fd], 0, nbr_char);
		tmp = ft_strdup(s[fd] + nbr_char + 1);
		free(s[fd]);
		s[fd] = tmp;
		if (!(s[fd][0]))
			ft_strdel(&s[fd]);
	}
	return (1);
}

int get_next_line(const int fd, char **line)
{
	int			byte;
	char		buff[BUFF_SIZE + 1];
	static char *s[OPEN_MAX];
	char		*tmp;

	if ((fd > 255) || (fd < 0) || !(line))
		return (-1);
	while ((byte = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[byte] = '\0';
		if (!(s[fd]))
			s[fd] = ft_strnew(0);
		if((tmp = ft_strjoin(s[fd], buff)) == NULL)
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (byte < 0)
		return (-1);
	else if ((byte == 0) && !(s[fd]))
		return (0);
	else
		return (prepare_line(s, line, fd));
}