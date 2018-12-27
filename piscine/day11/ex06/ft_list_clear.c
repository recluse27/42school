#include <stdlib.h>
#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *elem;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		elem= *begin_list;
		*begin_list = (*begin_list)->next;
		free(elem);
	}
	*begin_list = NULL;
}