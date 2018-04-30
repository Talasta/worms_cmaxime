#include "worms.h"

int		refresh(void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	//ft_putnbr(time(NULL)); ft_putchar('\n');
	mlx->cnf.time = (mlx->cnf.time + 1);
	update_time_status(mlx);
	update_time_objects(&(mlx->cnf.object), mlx);
	w_update_objs(mlx->cnf.object, mlx->cnf.map);
	*mlx = w_image_drawer(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	*mlx = w_image_drawer2(*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 780, 10, 0x00ff0000, ft_itoa(mlx->cnf.timer - time(NULL)));
	timer_print(mlx->cnf.object, mlx);
	return (0);
}
