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

int		get_inc_x(int x, int y, int *map)
{
	int i;

	i = 0;
	while (1)
	{
		if (get_pxl_val(map, x + i, y) == WORMS_COLOR_BACK)
			return (1);
		if (get_pxl_val(map, x - i, y) == WORMS_COLOR_BACK)
			return (-1);
		i++;
	}
}

t_object 	*w_recalculate_y(t_object *obj, int *map)
{
	int x;
	int y;
	int i;

	i = 0;
	x = (int)obj->x;
	y = (int)obj->y;
	i = get_inc_x(x, y, map);
	while (get_pxl_val(map, x, y) != WORMS_COLOR_BACK)
	{
		if (obj->vx != 0)
			x += i;
		if (obj->vy != 0)
		y = (obj->vy >= 0) ? y - 1 : y + 1;
	}
	if (get_pxl_val(map, x, y + 1) == WORMS_COLOR_BACK)
	{
		y++;
	}
	obj->y = (double)(y);
	obj->x = (double)(x);
	return (obj);
}

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

//TODO Mask ne reconnais pas bien les pentes
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
	//ft_putnbr(i); ft_putchar('\n');
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
		/*
		if (obj->vy > 2.0)
			obj->vy *= -1.0 / ABSORBANCE_T;
		else
			obj->vy = 0.0;
		obj->vx /= (0.2 / (obj->vx * obj->vx) + ABSORBANCE_T);
		*/
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

int		refresh(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	mlx->cnf.time = (mlx->cnf.time + 1);
	w_update_objs(mlx->cnf.object, mlx->cnf.map);
	*mlx = w_image_drawer(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	*mlx = w_image_drawer2(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	return (0);
}

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

	if (get_pxl_val(map, obj->x, obj->y + 1) != WORMS_COLOR_BACK)
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

t_mlx arrow_controls(t_mlx mlx, double key)
{
	t_object 	*obj;
	t_list		*objects;

	objects = mlx.cnf.object;
	while (objects)
	{
		obj = objects->content;
		move_worm(obj, key, mlx.cnf.map);
		objects = objects->next;
	}
	return (mlx);
}

t_mlx jump(t_mlx mlx)
{
	t_object 	*obj;
	t_list		*objects;

	objects = mlx.cnf.object;
	while (objects)
	{
		obj = objects->content;
		if (obj->type == 1 && get_pxl_val(mlx.cnf.map, obj->x, obj->y + 1) != WORMS_COLOR_BACK)
		{
			obj->vy = -1.0;
			obj->vx = obj->ori == 1 ? 1.0 : -1.0;
		}
		objects = objects->next;
	}
	return (mlx);
}

t_mlx throw_grenade(t_mlx mlx)
{
	t_object 	*obj;
	t_object	obj1;
	t_list		*objects;

	objects = mlx.cnf.object;
	while (objects)
	{
		obj = objects->content;
		if (obj->type == 1)
		{
			obj1.vy = -4.0;
			obj1.vx = obj->ori == 1 ? 2.0 : -2.0;
			obj1.x = obj->x;
			obj1.y = obj->y;
			obj1.m = 0.008;
			obj1.ori = 0;
			obj1.type = 2;
			ft_lstaddend(&(objects), ft_lstnew(&obj1, sizeof(t_object)));
		}
		objects = objects->next;
	}
	return (mlx);
}

int		actions(int key_hook, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	// 123 < | 124 >
	ft_putnbr(key_hook); ft_putchar('\n');
	if (key_hook == 123 || key_hook == 124)
		*mlx = arrow_controls(*mlx, (key_hook == 124) ? 0.5 : -0.5);
	if (key_hook == 49)
		*mlx = jump(*mlx);
	if (key_hook == 12)
		*mlx = throw_grenade(*mlx);
	if (key_hook == 53)
	{
		mlx_destroy_window(mlx, mlx->win);
		exit(1);
	}
	return (0);
}

int		mouse_on(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
  x = y + button;
	return (0);
}

int		mouse(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

  x = y + button;
	mlx = (t_mlx*)param;
	return (0);
}

int		drag_drop(int x, int y, void *param)
{
	t_mlx	*mlx;

  x = y;
	mlx = (t_mlx*)param;
	return (0);
}
