/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ls.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 16:38:23 by vlazuka           #+#    #+#             */
/*   Updated: 2018/09/23 18:00:43 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int		main(int argc, char *argv[])
{
	DIR *mydir;
	struct dirent *myfile;
	struct stat mystat;

	char buf[512];
	mydir = opendir(argv[1]);
	while((myfile = readdir(mydir)) != NULL)
	{
		sprintf(buf, "%s/%s", argv[1], myfile->d_name);
		stat(buf, &mystat);
		printf("%zu", mystat.st_size);
		printf(" %s\n", myfile->d_name);
	}
	closedir(mydir);

	return (0);
}
