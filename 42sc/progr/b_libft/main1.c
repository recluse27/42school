#include "libft.h"
#include "stdio.h"

int     main()
{
	printf("Chechking ISDIGIT %d should be 1\n", ft_isdigit(55));
	printf("Chechking ISDIGIT %d should be 0\n", ft_isdigit(99));
	printf("-----------------------------------------------\n");
	printf("Checking strchr %s should be eXXXX\n", ft_strchr("asdgafgehsff", 101));
	printf("-----------------------------------------------\n");
	printf("Checking strcmp1 %d should be 0\n", ft_strcmp("HELLO", "HELLO"));
	printf("Checking strcmp2 %d should be 7\n", ft_strcmp("KEKEK", "DSFDSFDS"));
	printf("-----------------------------------------------\n");
	char strcpy1[256];
	printf("Checking strcpy %s should be HELLOBOBI\n", ft_strcpy(strcpy1, "HELLOBOBI"));
	printf("-----------------------------------------------\n");
	printf("Checking strdup %s should be LOLKEK\n", ft_strdup("LOLKEK"));
	printf("-----------------------------------------------\n");
	printf("Checking strlen %zu should be 6\n", ft_strlen("PRIVET"));
	printf("-----------------------------------------------\n");
	printf("Checking strncpy %s should be PRI\n", ft_strncpy(strcpy1, "PRIVETAGAIN", 3));
	printf("-----------------------------------------------\n");
	printf("Checking tolower %c should be d\n", ft_tolower(68));
	printf("-----------------------------------------------\n");
	printf("Checking toupper %c should be C\n", ft_toupper(99));
	printf("-----------------------------------------------\n");
	return 0;
}
