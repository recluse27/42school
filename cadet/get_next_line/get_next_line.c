/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:28:28 by vlazuka           #+#    #+#             */
/*   Updated: 2018/11/07 23:38:13 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				check_line(char **str, char **line, int fd, int num)
{
	char		*tmp;
	int			len;

	len = 0;
	while (str[fd][len] != '\0' && str[fd][len] != '\n')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][len] == '\0')
	{
		if (num == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			num;
	static char	*str[4864];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((num = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!str[fd])
			str[fd] = ft_strnew(1);
		buff[num] = '\0';
		tmp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (num == 0 && (!str[fd] || str[fd][0] == '\0'))
		return (0);
	if (num < 0)
		return (-1);
	return (check_line(str, line, fd, num));
}
