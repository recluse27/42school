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
char *dirpath = '.';

# define O_FORMAT	options[0]
# define O_SORT		options[1]
# define O_FILES	options[2]
# define O_RECURS	options[3]
# define O_COLORS	options[4]
# define O_REVERS	options[5]

#endif

int ft_strlen(const char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void b_ls(int i, char **argv)
{
	struct stat buf;
	struct dirent *sd = NULL;
	node *head;
	long long int blocks = 0;
	char *dirpath;
	DIR *dir;

	if(argv[i] == NULL)
		dirpath = ".";
	else
		dirpath = argv[i];
	if((dir = opendir(dirpath)) == NULL)
	{
		printf("b_ls: %s: No Such a file or directory.", argv[i]);
		return ;
	}
	if(L == 1)
	{
		while((sd = readdir(dir)))
		{
			if((sd->d_name[0] == '.' && A == 1) || (sd->d_name[0] != '.'))
			{
				lstat(getpath(dirpath, sd->d_name), &buf);
				blocks += buf.st_blocks;
			}
		}
		printf("total %lld\n", blocks);
		closedir(dir);
	}
	dir = opendir(dirpath);
	while((sd = readdir(dir)))
	{
		lstat(getpath(dirpath, sd->d_name), &buf);
		head = insertend(head, sd, buf);
	}
	n_sort(head);
	if(T == 1)
		t_sort(head);
	while(head)
	{
		printer(head, dirpath);
		head = head->next;
	}
	closedir(dir);
}

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