#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
    t_list *reversed;
    t_list *rest;
    t_list *next;
    
	reversed = NULL;
	rest = *begin_list;
	while (rest)
	{
		next = rest->next;
		rest->next = reversed;
		reversed = rest;
		rest = next;
	}
	*begin_list = reversed;
}