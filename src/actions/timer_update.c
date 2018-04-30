#include "worms.h"

t_list *get_next_worm(t_list *curr, t_list *list)
{
	curr = curr->next;
	while (curr)
	{
		if (((t_object*)(curr->content))->type == 1)
			return (curr);
			curr = curr->next;
	}
	return (get_worm(list));
}

void 	update_time_status(t_mlx *mlx)
{
	if (mlx->cnf.timer < time(NULL))
	{
		mlx->cnf.current = get_next_worm(mlx->cnf.current, mlx->cnf.object);
		mlx->cnf.timer = time(NULL) + 30;
		mlx->cnf.status = 0;
	}
}
