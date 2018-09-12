// #include "libft.h"
#include "libft.h"
//#include <stdio.h>
#include <assert.h>
//#include <string.h>
#include <ctype.h>
#include <stdio.h>

int		main(void)
{
	// assert(ft_memset("Hello world",'-', 6) == memset("Hello world",'-', 6));
	// assert(ft_memset("", '*', 9) == memset("", '*', 9));
	// assert(ft_memset("fwfsdfs", 3, 2) == memset("fwfsdfs", 3, 2));
	// assert(ft_memset("fdv sdf", '1', 3) == memset("fdv sdf", '1', 3));

	assert(ft_strlen("Hello") == strlen("Hello"));
	assert(ft_strlen("\0") == strlen("\0"));
	assert(ft_strlen("123456789pokjghfds") == strlen("123456789pokjghfds"));
	assert(ft_strlen("") == strlen(""));

	//assert(ft_strdup("") == strdup(""));
	// assert(ft_strdup("Hello") == strdup("Hello"));
	// assert(ft_strdup("432fgdb0") == strdup("432fgdb0"));
	// assert(ft_strdup("12344") == strdup("12344"));
	// assert(ft_strdup("\0") == strdup("\0"));

	assert(ft_strcpy("Hello", "pan") == strcpy("Hello", "pan"));
	assert(ft_strcpy("asd", "ba") == strcpy("asd", "ba"));
	assert(ft_strcpy("asd", "b") == strcpy("asd", "b"));
	assert(ft_strcpy(" ", "2") == strcpy(" ", "2"));
	assert(ft_strcpy("", "fd") == strcpy("", "fd"));

	assert(ft_strncpy("Hello", "pan", 2) == strncpy("Hello", "pan", 2));
	assert(ft_strncpy("Hello", "pan", 4) == strncpy("Hello", "pan", 4));
	assert(ft_strncpy("asd", "ba", 2) == strncpy("asd", "ba", 2));
	assert(ft_strncpy("asd", "b", 2) == strncpy("asd", "b", 2));

	// assert(ft_strchr("ABC", 'b') == strchr("ABC", 'b'));
	// assert(ft_strchr("bbbbb", 'b') == strchr("bbbbb", 'b'));
	// assert(ft_strchr("gfsdc", 'c') == strchr("gfsdc", 'c'));
	// assert(ft_strchr("", '\0') == strchr("", '\0'));
	// assert(ft_strchr("cvb", 'a') == strchr("cvb", 'a'));
  // 
	// assert(ft_strcmp(" ", " ") == strcmp(" ", " "));
	// assert(ft_strcmp("", "") == strcmp("", ""));
	// assert(ft_strcmp("\0", "") == strcmp("\0", ""));
	// assert(ft_strcmp("vbT", "vbtD") == strcmp("vbT", "vbtD"));
	// assert(ft_strcmp("a", "A") == strcmp("a", "A"));
	// assert(ft_strcmp("abc1", "abc2") == strcmp("abc1", "abc2"));

	assert(ft_isdigit('-') == isdigit('-'));
	assert(ft_isdigit('a') == isdigit('a'));
	assert(ft_isdigit(-0) == isdigit(-0));
	assert(ft_isdigit(-10) == isdigit(-10));
	assert(ft_isdigit(1) == isdigit(1));
	assert(ft_isdigit(0) == isdigit(0));

	assert(ft_toupper('=') == toupper('='));
	assert(ft_toupper(1) == toupper(1));
	assert(ft_toupper('Z') == toupper('Z'));
	assert(ft_toupper('A') == toupper('A'));
	assert(ft_toupper('z') == toupper('z'));
	assert(ft_toupper('a') == toupper('a'));

	assert(ft_tolower(3) == tolower(3));
	assert(ft_tolower('-') == tolower('-'));
	assert(ft_tolower('Z') == tolower('Z'));
	assert(ft_tolower('A') == tolower('A'));
	assert(ft_tolower('z') == tolower('z'));
	assert(ft_tolower('a') == tolower('a'));
	return (0);
}
