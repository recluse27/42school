/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlazuka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 14:39:44 by vlazuka           #+#    #+#             */
/*   Updated: 2018/10/13 14:39:56 by vlazuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_LS_H
# define B_LS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <stdlib.h>

// typedef struct tmp
// {
// 	struct dirent sd;
// 	struct stat buf;
// 	struct tmp *next;
// }		node;

typedef struct		s_file
{
	char			*name;
	char			*path;
	char			*buff;
	struct s_file	*next;
}					t_file;

int A = 0;
int L = 0;
int R = 0;
int T = 0;

# define O_FORMAT	options[0]
# define O_SORT		options[1]
# define O_FILES	options[2]
# define O_RECURS	options[3]
# define O_COLORS	options[4]
# define O_REVERS	options[5]

#endif

int main(int argc, char *argv[])
{
	int i;
   
	i = flags(argv);
	if(argc && argv[i] == NULL)
		b_ls(i, argv);
	while(argv[i])
	{
		printf("%s:\n", argv[i]);
		b_ls(i, argv);
		i++;
	}
}