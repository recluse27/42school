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

typedef struct tmp
{
	struct dirent sd;
	struct stat buf;
	struct tmp *next;
}		node;

int A = 0;
int L = 0;
int R = 0;
int T = 0;
// char *dirpath = ".";

#endif

int		strlen(const char *str)
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

int flags(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		if(argv[i][0] == '-')
		{
			while(argv[i][j])
			{
				if(argv[i][j] == 'a')
					A = 1;
				if(argv[i][j] == 'l')
					L = 1;
				if(argv[i][j] == 'r')
					R = 1;
				if(argv[i][j] == 't')
					T = 1;
				j++;
			}
		}
		i++;
	}
	return i;
}

char *getpath(char *dirpath, char *str)
{
	int i = 0;
	int j = 0;
	int size;
	char *word;

	size = ft_strlen(dirpath) + ft_strlen(str) + 2;
	word = (char*)malloc(sizeof(char) * size);

	while(dirpath[i])
	{
		word[i] = dirpath[i];
		i++;
	}
	word[i] = '/';
	i++;
	while(str[j])
	{
		word[i] = str[j];
		j++;
		i++;
	}
	word[i] = '\0';
	return word;
}

node *createnewlist(struct dirent *sd, struct stat *buf)
{
	node *new;
	new = (node*)malloc(sizeof(node));
	new->sd = *sd;
	new->buf = *buf;
	new->next = NULL;
	return new;
}

node *insertend(node *head, struct dirent *sd, struct stat buf)
{
	node *tmp = head;
	node *newnode;
	if(head == NULL)
		return(createnewlist(sd, &buf));
	while(head->next)
		head = head->next;
	newnode = (node*)malloc(sizeof(node));
	newnode->sd = *sd;
	newnode->buf = buf;
	newnode->next = NULL;
	head->next = newnode;
	return tmp;
}

void swapdata(node *dest, node *src)
{
	node *tmp = dest;
	tmp->sd = src->sd;
	tmp->buf = src->buf;
}

void nodeswap(node *one, node *two)
{
	node *tmp;
	tmp = (node*)malloc(sizeof(node));
	swapdata(tmp, one);
	swapdata(one, two);
	swapdata(two, tmp);
}

void n_sort(node *head)
{
	node *b = head;
	node *s;
	while(b)
	{
		s = head;
		while(s->next)
		{
			if(R ? ft_strcmp(s->sd.d_name, s->next->sd.d_name) < 0 : ft_strcmp(s->sd.d_name, s->next->sd.d_name) > 0)
				nodeswap(s, s->next);
			s = s->next;
		}
		b = b->next;
	}
}

void t_sort(node *head)
{
	node *b = head;
	node *s;
	while(b)
	{
		s = head;
		while(s->next)
		{
			if(R ? (s->buf.st_mtime > s->next->buf.st_mtime) : (s->buf.st_mtime < s->next->buf.st_mtime))
				nodeswap(s, s->next);
			if(s->buf.st_mtime == s->next->buf.st_mtime)
			{
				if(R ? (s->buf.st_mtimespec.tv_nsec > s->next->buf.st_mtimespec.tv_nsec) : (s->buf.st_mtimespec.tv_nsec < s->next->buf.st_mtimespec.tv_nsec))
					nodeswap(s, s->next);
			}
			s = s->next;
		}
		b = b->next;
	}
}

void modeprint(mode_t mode)
{
	char c;
	int i = 0;
	char tmp[10];
	char tab[] = "rwxrwxrwx";
	while(i < 9)
	{
		tmp[i] = (mode & (1 << (8 - i)) ? tab[i] : '-');
		i++;
	}
	tmp[i] = '\0';
	if ((mode & S_IFDIR) == S_IFDIR)
		c = 'd';
	if ((mode & S_IFCHR) == S_IFCHR)
		c = 'c';
	if ((mode & S_IFIFO) == S_IFIFO)
		c = 'p';
	if ((mode & S_IFBLK) == S_IFBLK)
		c = 'b';
	if ((mode & S_IFREG) == S_IFREG)
		c = '-';
	if ((mode & S_IFLNK) == S_IFLNK)
		c = 'l';
	if ((mode & S_IFSOCK) == S_IFSOCK)
		c = 's';
	printf("%c%s ", c, tmp);
}

void timeconverter(char *time)
{
	int i = 4;
	while(i <= 15)
	{
		printf("%c", time[i]);
		i++;
	}
}

void printer(node *head, char *dirpath)
{
	struct stat buf;

	if((head->sd.d_name[0] == '.' && A == 1) || (head->sd.d_name[0] != '.'))
	{
		if(L == 1)
		{
			lstat(getpath(dirpath, head->sd.d_name), &buf);
			modeprint(buf.st_mode);
			printf("%i ", buf.st_nlink);
			printf("%s ", getpwuid(buf.st_uid)->pw_name);
			printf("%s ", getgrgid(buf.st_gid)->gr_name);
			printf("%lld\t", buf.st_size);
			timeconverter(ctime(&buf.st_mtime));
			printf(" ");
		}
		printf("%s", head->sd.d_name);
		printf("\t");
	}
}

void b_ls(int i, char **argv)
{
	struct stat buf;
	struct dirent *sd = NULL;
	node *head;
	long long int blocks = 0;
	// char *dirpath;
	DIR *dir;

	// if(argv[i] == NULL)
	// 	dirpath = ".";
	// else
	if(argv[i] != NULL)
		dirpath = argv[i];
	if((dir = opendir(dirpath)) == NULL)
	{
		printf("b_ls: %s: No such file or directory", argv[i]);
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

int main(int argc, char **argv)
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