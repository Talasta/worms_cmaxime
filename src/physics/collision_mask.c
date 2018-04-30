#include "worms.h"

unsigned char *get_collision_const(void)
{
	static unsigned char mask[12] = {
		0b00101001,
		0b11010000,
		0b00000111,
		0b01101000,
		0b10010100,
		0b00001011,
		0b11100000,
		0b00010110,
		0b10000000,
		0b00100000,
		0b00000100,
		0b00000001
	};

	return (mask);
}

unsigned char get_collision_mask(int x, int y, int *map)
{
	unsigned char mask;

	mask = 0b00000000;
	mask = (get_pxl_val(map, x - 1, y - 1) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 7);
	mask = (get_pxl_val(map, x, y - 1) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 6);
	mask = (get_pxl_val(map, x + 1, y - 1) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 5);
	mask = (get_pxl_val(map, x - 1, y) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 4);
	mask = (get_pxl_val(map, x + 1, y) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 3);
	mask = (get_pxl_val(map, x - 1, y + 1) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 2);
	mask = (get_pxl_val(map, x, y + 1) != WORMS_COLOR_BACK) ? mask : mask | (0b00000001 << 1);
	mask = (get_pxl_val(map, x + 1, y + 1) != WORMS_COLOR_BACK) ? mask : mask | 0b00000001;
	return (mask);
}


int 	get_transpho(int x, int y, int *map)
{
	unsigned char mask;
	unsigned char *tab_mask;
	int i;

	mask = get_collision_mask(x, y, map);
	tab_mask = get_collision_const();
	i = -1;
	while (++i < 12)
	{
		if ((mask & tab_mask[i]) == 0)
			return (i);
	}
	return (-1);
}

void 	w_recalculate_speed(t_object *obj, int *map)
{
	int i;
	double tmp;

	i = get_transpho(obj->x, obj->y, map);
	if (i == -1 || obj->type == 1)
	{
		obj->vx = 0.0;
		obj->vy = 0.0;
	}
	else
	{
		if (i == 1 || i == 5 || i == 8 || i == 11)
		{
			tmp = obj->vx;
			obj->vx = -1.0 * obj->vy;
			obj->vy = -1.0 * tmp;
		}
		if (i == 0 || i == 4)
			obj->vx *= -1.0;
		if (i == 2 || i == 6)
			obj->vy *= -1.0;
		if (i == 3 || i == 7 || i == 9 || i == 10)
		{
			tmp = obj->vx;
			obj->vx = obj->vy; //-1.0 * obj->vy;
			obj->vy = tmp; //-1.0 * tmp;
		}
	}
	obj->vy /= ABSORBANCE_T;
	obj->vx /= (0.2 / (obj->vx * obj->vx) + ABSORBANCE_T);
}
