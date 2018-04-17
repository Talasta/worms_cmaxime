#include "worms.h"

t_img	set_img_pxl(t_img img, int x, int y, int color)
{
	if (x < img.size_line / 4 && y < img.size_column && x > -1 && y > -1)
		img.data[x + (y * img.size_line / 4)] = color;
	return (img);
}

int		get_pxl_val(int *img, int x, int y)
{
	if (x < 800 && y < 500 && x > -1 && y > -1)
		return (img[x + (y * 800)]);
	return (-1);
}

t_img   draw_test(t_img img, int *map)
{
  int   i;
  int   color;
  int   x;
  int   y;

  i = -1;
  while (++i < 800 * 500)
  {
    color = map[i];
    x = i % 800;
    y = i / 800;
    img = set_img_pxl(img, x, y, color);
  }
  return (img);
}

t_img		w_draw_box(t_img img, int x, int y, int size)
{
	int i;
	int j;
	//(void)size;
	//img = set_img_pxl(img, x, y, 0x00ff0000);

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			img = set_img_pxl(img, x + i - size / 2, y + j - size + 1, 0x00ff0000);
		}
	}
	return (img);
}

#define RED 0x00ff0000
#define BLE 0x000000ff
#define BCK 0x00000000
#define FSH 0x00ffa5f7
#define WTH 0x00ffffff
#define GR1 0x008c8c8c
#define GR2 0x00525252
#define GR3 0x00707070
#define GN1 0x003a741a
#define GN2 0x0096d161
#define GN3 0x0073c734

int *get_arrow_graph(void)
{
	static int worm[100] = {
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		BLE, BLE, BLE, BLE, BLE, BLE, BLE, BLE, BLE, RED,
		RED, BLE, BLE, BLE, BLE, BLE, BLE, BLE, RED, RED,
		RED, RED, BLE, BLE, BLE, BLE, BLE, RED, RED, RED,
		RED, RED, RED, BLE, BLE, BLE, RED, RED, RED, RED,
		RED, RED, RED, RED, BLE, RED, RED, RED, RED, RED
};

	return (worm);
}

int *get_grenad_graph(void)
{
	static int worm[100] = {
		RED, RED, GR1, GR1, GR1, GR1, RED, RED, RED, RED,
		RED, GR2, GR1, GR1, GR1, GR1, GR3, GR3, RED, RED,
		GR3, GN1, GN1, GR1, GN1, GN1, GN1, GR3, GR3, RED,
		GR3, GN1, GN2, GR1, GN2, GN2, GN1, RED, GR3, GR3,
		GN1, GR3, GR3, GN3, GN1, GN1, GN2, GN1, RED, GR3,
		GN1, GN3, GN3, GN1, GN3, GN3, GN3, GN1, RED, GR3,
		GN1, GN2, GN1, GN3, GN1, GN1, GN2, GN1, RED, RED,
		GN1, GN3, GN3, GN1, GN3, GN3, GN3, GN1, RED, RED,
		RED, GN1, GN2, GN2, GN2, GN2, GN1, RED, RED, RED,
		RED, GN1, GN1, GN1, GN1, GN1, GN1, RED, RED, RED
};

	return (worm);
}

int *get_worms_graph(void)
{
	static int worm[238] = {
	RED, RED, BCK, BCK, BCK, BCK, BCK, BCK, RED, RED, RED, RED, RED, RED,
	RED, BCK, FSH, FSH, FSH, FSH, FSH, FSH, BCK, RED, RED, RED, RED, RED,
	BCK, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, WTH, WTH, FSH, WTH, WTH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, WTH, BCK, FSH, BCK, WTH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, WTH, BCK, FSH, BCK, WTH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, WTH, BCK, FSH, BCK, WTH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, WTH, WTH, FSH, WTH, WTH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	BCK, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, BCK, RED, RED, RED, RED,
	RED, BCK, FSH, FSH, FSH, FSH, BCK, FSH, BCK, RED, RED, RED, RED, RED,
	RED, RED, BCK, BCK, BCK, BCK, FSH, FSH, BCK, RED, RED, RED, RED, RED,
	RED, RED, BCK, FSH, FSH, FSH, FSH, BCK, RED, RED, RED, RED, RED, RED,
	RED, BCK, FSH, FSH, FSH, FSH, FSH, BCK, RED, BCK, BCK, RED, RED, RED,
	RED, BCK, FSH, FSH, FSH, FSH, FSH, BCK, BCK, FSH, FSH, BCK, RED, RED,
	RED, BCK, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, BCK, RED,
	RED, BCK, FSH, FSH, FSH, FSH, FSH, FSH, FSH, FSH, BCK, FSH, FSH, BCK,
	RED, RED, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, RED, BCK, BCK, RED
};

	return (worm);
}

t_img w_draw_worm(t_img img, int x, int y, int side)
{
	int *worm;
	int i;

	worm = get_worms_graph();
	i = -1;
	while (++i < 238)
	{
		if (worm[i] != RED)
		{
			if (side == 0)
				img = set_img_pxl(img, x + (i % 14) - 6, y + (i / 14) - 15, worm[i]);
			else
				img = set_img_pxl(img, x - (i % 14) + 6, y + (i / 14) - 15, worm[i]);
		}
	}
	return (img);
}

t_img w_draw_arrow(t_img img, int x, int y)
{
	int *worm;
	int i;

	worm = get_arrow_graph();
	i = -1;
	while (++i < 100)
	{
		if (worm[i] != RED)
		{
			img = set_img_pxl(img, x + (i % 10) - 5, y + (i / 10) - 30, RED);
		}
	}
	return (img);
}

t_img w_draw_gren(t_img img, int x, int y, int side)
{
	int *worm;
	int i;

	worm = get_grenad_graph();
	(void)side;
	i = -1;
	while (++i < 100)
	{
		if (worm[i] != RED)
		{
			img = set_img_pxl(img, x + (i % 10) - 5, y + (i / 10) - 5, worm[i]);
		}
	}
	return (img);
}

t_img 	w_draw_viseur(t_img img, t_object *obj, int angle)
{
	double rad;
	double x;
	double y;
	int i;

	angle = obj->ori == 1 ? 360 - angle : angle;
	rad = (double)(angle + 90) * M_PI / 180.0;
	x = (cos(rad) * 50.0) + obj->x;
	y = (sin(rad) * 50.0) + obj->y;
	i = -1;
	while (++i < 9)
	{
		img = set_img_pxl(img, x + i - 4, y - 7, RED);
		img = set_img_pxl(img, x, y + i - 4 - 7, RED);
	}
	return (img);
}

t_mlx		w_image_objects(t_mlx mlx)
{
	t_list *object;
	t_object *obj;

	object = mlx.cnf.object;
	while (object)
	{
		obj = object->content;
		if (obj->type == 1)
			mlx.img = w_draw_worm(mlx.img, obj->x, obj->y, obj->ori);
		if (obj->type == 2)
			mlx.img = w_draw_gren(mlx.img, obj->x, obj->y, obj->ori);
		object = object->next;
	}
	obj = mlx.cnf.current->content;
	mlx.img = w_draw_arrow(mlx.img, obj->x, obj->y);
	mlx.img = w_draw_viseur(mlx.img, obj, mlx.cnf.angle);
	return (mlx);
}

t_mlx   w_image_drawer2(t_mlx mlx)
{
	int i;
	int j;

	i = -1;
	while (++i < 800)
	{
		j = 10 * sin((-i + 20 + mlx.cnf.time) * 0.015) + 450;
		while (j < 500)
		{
			mlx.img = set_img_pxl(mlx.img, i, j, 0x50008bb1);
			j++;
		}
	}
	i = -1;
	while (++i < 800)
	{
		j = 7 * sin((i + mlx.cnf.time) * 0.01) + 450;
		while (j < 500)
		{
			mlx.img = set_img_pxl(mlx.img, i, j, 0x6005246b);
			j++;
		}
	}
  return mlx;
}

t_mlx   w_image_drawer(t_mlx mlx)
{
  mlx.img = draw_test(mlx.img, mlx.cnf.map);
	mlx = w_image_objects(mlx);
  return mlx;
}
