#include "worms.h"

int		get_inc_x(int x, int y, int *map)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < 50)
	{
		if (get_pxl_val(map, x + i, y) == WORMS_COLOR_BACK)
			return (1);
		if (get_pxl_val(map, x - i, y) == WORMS_COLOR_BACK)
			return (-1);
		i++;
	}
	return (0);
}

int		get_inc_y(int x, int y, int *map)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < 50)
	{
		if (get_pxl_val(map, x, y + i) == WORMS_COLOR_BACK)
			return (1);
		if (get_pxl_val(map, x, y - i) == WORMS_COLOR_BACK)
			return (-1);
		i++;
	}
	return (0);
}

t_object 	*w_recalculate_y(t_object *obj, int *map)
{
	int x;
	int y;
	int i;
	int j;

	x = (int)obj->x;
	y = (int)obj->y;
	i = get_inc_x(x, y, map);
	j = get_inc_y(x, y, map);
	while (get_pxl_val(map, x, y) != WORMS_COLOR_BACK)
	{
		if (obj->vx != 0)
			x += i;
		if (obj->vy != 0)
			y += j;
	}
	if (get_pxl_val(map, x, y + 1) == WORMS_COLOR_BACK)
	{
		y++;
	}
	obj->y = (double)(y);
	obj->x = (double)(x);
	return (obj);
}
