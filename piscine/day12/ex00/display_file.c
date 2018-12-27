/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 20:30:05 by vlazuka           #+#    #+#             */
/*   Updated: 2018/08/09 20:59:46 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int		file;
	char	ch;

	if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file < 0)
			return (0);
		while (read(file, &ch, 1))
			write(1, &ch, 1);
		close(file);
	}
	return (0);
}
