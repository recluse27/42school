/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:28:04 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/09 23:04:45 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	display(char *str)
{
	int		file;
	char	buffer[30720];
	ssize_t	bytes;

	file = open(str, O_RDWR);
	if (file < 0)
	{
		write(2, "cat: ", 5);
		write(2, str, ft_strlen(str));
		if (errno == 21)
			write(2, ": Is a directory\n", 17);
		else if (errno == 2)
			write(2, ": No such file or directory\n", 28);
		else if (errno == 13)
			write(2, ": Permission denied\n", 20);
	}
	else
	{
		while ((bytes = read(file, &buffer, 30720)))
			write(1, &buffer, bytes);
	}
	close(file);
}

int		main(int argc, char *argv[])
{
	int count;

	count = 1;
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		while (count < argc)
		{
			display(argv[count]);
			count++;
		}
	return (0);
}
