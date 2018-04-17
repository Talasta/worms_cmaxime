#include "worms.h"

t_list	*add_worm(t_list *object, int x, int y, double vx)
{
	t_object obj;

	obj.vx = vx;
	obj.vy = -2.0;
	obj.x = x;
	obj.y = y;
	obj.m = 0.004;
	obj.ori = 0;
	obj.type = 1;
	obj.live = 0;
	ft_lstaddend(&(object), ft_lstnew(&obj, sizeof(t_object)));
	return (object);
}

t_list	*init_worms(t_list *object)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		object = add_worm(object, 200 + i * 150, 200, 0.0);
	}
	//object = add_worm(object, 400, 200, 0.0);
	return (object);
}

t_list	*get_worm(t_list *object)
{
	t_object *obj;
	while (object)
	{
		obj = object->content;
		if (obj->type == 1)
			return (object);
		object = object->next;
	}
	return (NULL);
}

t_cnf	cnf_init(void)
{
	t_cnf		cnf;

  cnf.map = w_map_gen(1);
	cnf.time = 0;
	cnf.status = 0;
	cnf.timer = time(NULL);
	cnf.object = NULL;
	cnf.object = init_worms(cnf.object);
	cnf.current = get_worm(cnf.object);
	return (cnf);
}

t_mlx	visu_init(t_cnf cnf)
{
	t_mlx	mlx;
	size_t	size_x;
	size_t	size_y;

	size_x = 800;
	size_y = 500;
	mlx.mlx = mlx_init();
	mlx.cnf = cnf;
	mlx.img.size_column = size_y;
	mlx.win = mlx_new_window(mlx.mlx, size_x, size_y, "worms");
	mlx.img.img = mlx_new_image(mlx.mlx, size_x, size_y);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.img, &mlx.img.bpp, \
			&mlx.img.size_line, &mlx.img.endian);
	return (mlx);
}

int		main(void)
{
	t_mlx	mlx;
	t_cnf	cnf;

	cnf = cnf_init();
	mlx = visu_init(cnf);
	mlx = w_image_drawer(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx = w_image_drawer2(mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img.img, 0, 0);
	mlx_hook(mlx.win, 2, (1L << 0), actions, &mlx);
	//mlx_hook(mlx.win, 4, (1L << 3), mouse_on, &mlx);
	//mlx_hook(mlx.win, 5, (1L << 3), mouse, &mlx);
	//mlx_hook(mlx.win, 6, (1L << 2), drag_drop, &mlx);
	mlx_loop_hook(mlx.mlx, refresh, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
