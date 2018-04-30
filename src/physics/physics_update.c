#include "worms.h"

void 	w_speed(t_object *obj, int *map)
{
	if (get_pxl_val(map, obj->x, obj->y + 1) == WORMS_COLOR_BACK || obj->vy > 0.5 || obj->vy < -0.5)
		obj->vy += obj->m * WORMS_G / WORMS_F;
	else
		obj->vy = 0.0;
	obj->vx /= WORMS_F;
	(void)map;
}

void 	w_update_pos(t_object *obj, int *map)
{
	double i;
	int val;

	i = -1;
	val = WORMS_COLOR_BACK;
	while (++i < 11 && val != -1 && val == WORMS_COLOR_BACK)
	{
		val = get_pxl_val(map, (i * obj->vx / 10.0) + obj->x
		, (i * obj->vy / 10.0) + obj->y);
	}
	obj->x += ((i - 1.0) * obj->vx) / 10.0;
	obj->y += ((i - 1.0) * obj->vy) / 10.0;
	if (i < 10)
	{
		obj = w_recalculate_y(obj, map);
		w_recalculate_speed(obj, map);
	}
}

void 	w_update_objs(t_list *objects, int *map)
{
	t_object *obj;

	while (objects)
	{
		obj = objects->content;
		w_speed(obj, map);
		w_update_pos(obj, map);
		objects = objects->next;
	}
}
