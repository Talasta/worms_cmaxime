#include "worms.h"

void free_obj(t_list **object, t_list *elem)
{
	t_list 	*buff;
	t_list	*list;

	list = *object;
	if (list == elem)
	{
		buff = list;
		*object = elem->next;
		free(buff->content);
		free(buff);
	}
	while (list->next)
	{
		if (list->next == elem)
		{
			buff = list->next;
			list->next = list->next->next;
			free(buff->content);
			free(buff);
		}
		if (list->next)
			list = list->next;
	}
}
