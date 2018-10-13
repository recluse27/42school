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

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <dirent.h>

// int		main(int argc, char *argv[])
// {
// 	if (argc != 0)
// 	{
// 		DIR *mydir;
// 		struct dirent *myfile;
// 		struct stat mystat;

// 		char buf[512];
// 		mydir = opendir(argv[1]);
// 		while((myfile = readdir(mydir)) != NULL)
// 		{
// 			sprintf(buf, "%s/%s", argv[1], myfile->d_name);
// 			stat(buf, &mystat);
// 			printf("%zu", mystat.st_size);
// 			printf(" %s\n", myfile->d_name);
// 		}
// 		closedir(mydir);
// 	}

// 	return (0);
// }

typedef struct	s_args
{
	int			l;
	int			a;
	int			r;
	int			t;

	int			R;
	int			u;
	int			f;
	int			g;
	int			d;
}				t_args;

#define INIT_ARGS(x) t_args x = {.l = 0, .a = 0, .r = 0, .t = 0}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

void	parse(int n, char *arr[])
{
	int i;
	int j;

	t_args *flags;

	flags->l = 0;
	flags->a = 0;
	flags->r = 0;
	flags->t = 0;
	
	i = 0;
	if (arr[1][0] != '-')
		printf("%s\n", "WHERE IS '-' ???");
	else
	{
		while (arr[1][i] != '\0')
		{
			t_args->;
			i++;
		} 
	}
}

int		main(int argc, char *argv[])
{
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	unsigned int count = 0;

	curr_dir = getenv("PWD");
	if (argc == 3)
	{
		parse(argc - 1, argv);
	}
	if (!curr_dir)
	{
		printf("\n ERROR: Could not get the working directory\n");
		return (-1);
	}
	dp = opendir((const char*)curr_dir);
	if (!dp)
	{
		printf("\n ERROR: Could not open the working directory\n");
		return (-1);
	}
	//printf("\n");
	while ((dptr = readdir(dp)) != NULL)
	{
		if(dptr->d_name[0] != '.')
			printf("%s  ", dptr->d_name);
		count++;
	}

	return (0);
}