#include "worms.h"

int check_slop(int *map, int x, int y)
{
	int i;

	i = -1;
	while (1)
	{
		i++;
		if (get_pxl_val(map, x, y) == WORMS_COLOR_BACK)
		{
			if (get_pxl_val(map, x, y + i + 1) != WORMS_COLOR_BACK)
				return (i);
		}
		else if (get_pxl_val(map, x, y - i) == WORMS_COLOR_BACK)
			return (-i);
	}
	return (-10);
}

void  move_worm(t_object *obj, double key, int *map)
{
	int move;

	if (obj->type == 1 && get_pxl_val(map, obj->x, obj->y + 1) != WORMS_COLOR_BACK)
	{
		move = check_slop(map, obj->x + key, obj->y);
		if (move < 5 && move > -5)
		{
			obj->y += move;
			obj->x += key;
			obj->vy = 0.0;
			obj->vx = 0.0;
		}
		if (move >= 5)
		{
			obj->x += key;
			obj->vy = 0.0;
			obj->vx = 0.01;
		}
	}
	obj->ori = key == 0.5 ? 1 : 0;
}

t_mlx move_controls(t_mlx mlx, double key)
{
	t_object 	*obj;

	obj = mlx.cnf.current->content;
	move_worm(obj, key, mlx.cnf.map);
	return (mlx);
}
