#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		count;
	int		i;
	int		j;
	t_list	*current;
	void	*tmp;

	count = 0;
	current = begin_list;
	while (current && ++count)
		current = current->next;
	i = 0;
	while (i < count - 1)
	{
		j = i;
		current = begin_list;
		while (current && current->next && j < count - 1)
		{
			tmp = current->data;
			current->data = current->next->data;
			current->next->data = tmp;
			current = current->next;
			++j;
		}
		++i;
	}
}