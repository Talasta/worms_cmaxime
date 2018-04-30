#include "worms.h"

t_mlx throw_grenade(t_mlx mlx)
{
	t_object 	*obj;
	t_object	obj1;
	t_list		*objects;
	double    angle;

	objects = mlx.cnf.object;
	obj = mlx.cnf.current->content;
	if (obj->type == 1)
	{
		angle = (double)(mlx.cnf.angle - 90) * M_PI / 180.0;
		obj1.vy = sin(angle) * -6.0;
		obj1.vx = obj->ori == 1 ? cos(angle) * 5.0 : cos(angle) * -5.0;
		obj1.x = obj->x;
		obj1.y = obj->y;
		obj1.m = 0.008;
		obj1.ori = 0;
		obj1.type = 2;
		obj1.live = time(NULL) + mlx.cnf.gre_timer;
		ft_lstaddend(&(objects), ft_lstnew(&obj1, sizeof(t_object)));
	}
	mlx.cnf.status = 1;
	mlx.cnf.timer = time(NULL) + 5;
	return (mlx);
}

void update_gre_timer(t_mlx *mlx, int key_hook)
{
		if (key_hook == 18)
			mlx->cnf.gre_timer = 1;
		if (key_hook == 19)
			mlx->cnf.gre_timer = 2;
		if (key_hook == 20)
			mlx->cnf.gre_timer = 3;
		if (key_hook == 21)
			mlx->cnf.gre_timer = 4;
		if (key_hook == 23)
			mlx->cnf.gre_timer = 5;
}
