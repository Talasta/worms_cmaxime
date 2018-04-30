#include "worms.h"

int	*set_map_pxl(int *map, int x, int y, int color)
{
	if (x < 800 && y < 500 && x > -1 && y > -1)
		map[x + (y * 800)] = color;
	return (map);
}

void 	explode_map(t_mlx *mlx, t_object *obj)
{
	double			x;
	double			y;
	int			a;
	double		rad;
	double			i;

	if (obj->type == 2)
	{
		a = 0;
		while (a < 180)
		{
			rad = (double)a * M_PI / 180.0;
			x = cos(rad) * 20.0 + obj->x;
			y = sin(rad) * 20.0 + obj->y;
			i = sin((double)(360 - a) * M_PI / 180.0) * 20.0 + obj->y;
			while (i <= y)
			{
				mlx->cnf.map = set_map_pxl(mlx->cnf.map, x, i, WORMS_COLOR_BACK);
				i += 1.0;
			}
			a++;
		}
	}
}

void 	update_time_objects(t_list **object, t_mlx *mlx)
{
	t_list 		*list;
	t_object	*obj;

	list = *object;
	while (list)
	{
		obj = list->content;
		if (obj->live != 0 && obj->live < time(NULL))
		{
			explode_map(mlx, obj);
			free_obj(object, list);
		}
		list = list->next;
	}
}
