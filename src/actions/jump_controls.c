#include "worms.h"

t_mlx jump(t_mlx mlx)
{
	t_object 	*obj;

	obj = mlx.cnf.current->content;
	if (obj->type == 1 && get_pxl_val(mlx.cnf.map, obj->x, obj->y + 1) != WORMS_COLOR_BACK)
	{
		obj->vy = -1.2;
		obj->vx = obj->ori == 1 ? 1.0 : -1.0;
	}
	return (mlx);
}
