#include "worms.h"

void update_scope(t_mlx *mlx, int key_hook)
{
	if (key_hook == 126 && mlx->cnf.angle < 180)
	{
		mlx->cnf.angle++;
	}
	else if (mlx->cnf.angle > 0)
	{
		mlx->cnf.angle--;
	}
}
