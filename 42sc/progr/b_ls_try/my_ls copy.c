#ifndef
# define B_LS_H
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <stdlib.h>

int A = 0;
int L = 0;
int R = 0;
int T = 0;

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