#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*curr;
	unsigned int	count;

	curr = begin_list;
	count = -1;
	while (++count < nbr && curr)
		curr = curr->next;
	return (count == nbr ? curr : NULL);
}