#include "worms.h"

int		actions(int key_hook, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	ft_putnbr(key_hook); ft_putchar('\n');
	if (key_hook == 18 || key_hook == 19 || key_hook == 20 || key_hook == 21
		|| key_hook == 23)
		update_gre_timer(mlx, key_hook);
	if (key_hook == 125 || key_hook == 126)
		update_scope(mlx, key_hook);
	if (key_hook == 123 || key_hook == 124)
		*mlx = move_controls(*mlx, (key_hook == 124) ? 0.5 : -0.5);
	if (key_hook == 49)
		*mlx = jump(*mlx);
	if (key_hook == 12 && mlx->cnf.status == 0)
		*mlx = throw_grenade(*mlx);
	if (key_hook == 53)
	{
		mlx_destroy_window(mlx, mlx->win);
		exit(1);
	}
	return (0);
}
