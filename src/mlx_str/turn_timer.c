#include "worms.h"

void timer_print(t_list *list, t_mlx *mlx)
{
	t_object *obj;

	while (list)
	{
		obj = list->content;
		if (obj->type == 2)
			mlx_string_put(mlx->mlx, mlx->win, obj->x - 5, obj->y - 25, 0x00ff0000, ft_itoa(obj->live - time(NULL)));
		list = list->next;
	}
}
