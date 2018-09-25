#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void    total_count(DIR *dir, struct dirent *sd, t_flags flags, char *path)
{
	long long int blocks;
	struct stat        buf;

	blocks = 0;
	while((sd = readdir(dir)) != NULL)
	{
		if ((sd->d_name[0] == '.' && flags.flagA == 1) || (sd->d_name[0] != '.'))
		{
			lstat(retrieve_path(path, sd->d_name), &buf);
			blocks += buf.st_blocks;
		}
	}
	closedir(dir);
	printf("total %lld\n", blocks);
}

void    check_args(char *path, t_flags flags)
{
	DIR *dirStream = NULL;
	struct dirent  *dirEntry   = NULL;
	char    *dir_name;

	dir_name = path;
	if ((dirStream = opendir(dir_name)) == NULL)
	{
		printf("b_ls: %s: No such file or directory\n", dir_name);
		return;
	}
	if (flags.flagL == 1)
		total_count(dirStream, dirEntry, flags, path);
	dirStream = opendir(dir_name);
	while((dirEntry = readdir(dirStream)) != NULL)
		run_args(flags, dirEntry, path);
	closedir(dirStream);
}

void    assigning_rwx(int n, char *c1, char *c2, char *c3)
{
	if (n > 3)
		*c1 = 'r';
	if (n % 4 > 1)
		*c2 = 'w';
	if (n % 2 == 1)
		*c3 = 'x';
}

char    *conversion_mode(int n)
{
	int        i;
	char    *str;

	i = 0;
	str = (char *)malloc(sizeof(char) * 10);
	while (i < 10)
	{
		str[i] = '-';
		i++;
	}
	n = ft_atoi(ft_itoa_base(n, 8));
	i = 9;
	while (i > 0)
	{
		assigning_rwx(n % 10, &str[i - 2], &str[i - 1], &str[i]);
		n /= 10;
		i -= 3;
	}
	if (n == 40)
		str[0] = 'd';
	return (str);
}

void    run_args(t_flags flags, struct dirent *dirEntry, char *path)
{
	struct stat     buf;

	if (!path)
		return;
	if ((dirEntry->d_name[0] == '.' && flags.flagA == 1) || (dirEntry->d_name[0] != '.'))
	{
		if (flags.flagL == 1)
		{
			lstat(retrieve_path(path, dirEntry->d_name), &buf);
			printf("%s", conversion_mode(buf.st_mode));
			printf("  %d", buf.st_nlink);
			printf(" %s", getpwuid(buf.st_uid)->pw_name);
			printf("  %s", getgrgid(buf.st_gid)->gr_name);
			printf("  %lld\t",buf.st_size);
			time_conversion(ctime(&buf.st_mtime));
			printf(" ");
		}
		printf("%s",dirEntry->d_name);
		printf("\n");
	}
}

void    time_conversion(char *str)
{
	int        i;
	int        count;

	i = 0;
	while (str[i] != ' ')
		++i;
	++i;
	count = 0;
	while (str[i])
	{
		if (str[i] == ':')
			count++;
		if (count == 2)
			return;
		printf("%c",str[i]);
		++i;
	}
}

int        ft_strlen(char *str)
{
	int    len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char    *retrieve_path(char    *path, char    *name)
{
	/*    extern    char    **environ;
		  int        j;
		  int        i;
		  char    *str;

		  str = NULL;
		  j = 4;
		  while (environ[7][j])
		  ++j;
		  ++j;
		  i = 0;
		  while (path[i])
		  {
		  path++;
		  j++;
		  i++;
		  }
		  ++j;
		  str = malloc(sizeof(char) * j + 1);
		  j = 4;
		  i = 0;
		  while (environ[7][j])
		  {
		  str[i] = environ[7][j];
		  ++j;
		  ++i;
		  }
		  str[i] = '/';
		  ++i;
		  j = 0;
		  while (path[j])
		  {
		  str[i] = path[j];
		  ++j;
		  ++i;
		  }
		  printf("%s\n", str);
		  return (str);*/

	int        size;
	char    *str;
	int        i;
	int        j;

	size = ft_strlen(path) + ft_strlen(name) + 2;
	str = (char *)malloc(sizeof(char) * size);
	i = 0;
	j = 0;
	while (path[j])
	{
		str[i] = path[j];
		++i;
		++j;
	}
	str[i] = '/';
	++i;
	j = 0;
	while (name[j])
	{
		str[i] = name[j];
		++i;
		++j;
	}
	str[i] = '\0';
	return (str);
}

int        b_ls(int argc, char **argv)
{
	int        i;
	int        j;
	int        end;
	char    *all;
	t_flags        flags;

	flags.flagA = 0;
	flags.flagL = 0;
	flags.flagR = 0;
	flags.flagT = 0;
	all = "\0";
	if (argc == 1)
		check_args(".", flags);
	else
	{
		i = 1;
		end = 0;
		while (argv[i])
		{
			if (argv[i][0] == '-' && end == 0)
			{
				j = 0;
				while (argv[i][j] && end == 0)
				{
					if (argv[i][j] == 'l')
						flags.flagL = 1;
					else if (argv[i][j] == 'r')
						flags.flagR = 1;
					else if (argv[i][j] == 'a')
						flags.flagA = 1;
					else if (argv[i][j] == 't')
						flags.flagT = 1;
					else if (j != 0)
					{
						printf("b_ls: illegal option -- %c\nusage: b_ls [alrt] [file ...]\n", argv[i][j]);
						end = 2;
					}
					++j;
				}
				if (j == 1)
				{
					end = 1;
					check_args("-", flags);
				}
			}
			else
			{
				end = 1;
				check_args(argv[i], flags);
			}
			++i;
		}
		if (end == 0)
		{
			check_args(".", flags);
		}
	}
	printf("\nA = %d, L = %d, T = %d, R = %d", flags.flagA, flags.flagL, flags.flagT, flags.flagR);
	return(0);
}

int		main(int	argc, char **argv)
{
	if (argc > 0)
		b_ls(argc, argv);
	return (0);
}
