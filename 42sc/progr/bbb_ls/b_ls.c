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
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <dirent.h> 
  
int main(void) 
{ 
	char *curr_dir = NULL; 
	DIR *dp = NULL; 
	struct dirent *dptr = NULL; 
	unsigned int count = 0; 

	curr_dir = getenv("PWD"); 
	if(NULL == curr_dir) 
	{ 
		printf("\n ERROR : Could not get the working directory\n"); 
		return (-1); 
	} 

	dp = opendir((const char*)curr_dir);
	if (NULL == dp)
	{
		printf("\n ERROR : Could not open the working directory\n");
		return (-1);
	}

	printf("\n"); 
	for (count = 0; NULL != (dptr = readdir(dp)); count++) 
	{ 
		// Check if the name of the file/folder begins with '.' 
		// If yes, then do not display it. 
		if(dptr->d_name[0] != '.') 
			printf("%s  ",dptr->d_name); 
	}

	return (0); 
}