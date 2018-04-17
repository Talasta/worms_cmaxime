#include "worms.h"

int		kernel_antialiasing(int *new, int size, int i)
{
		int	j;
		int k;
		int tot;
		int index;

		tot = 0;
		j = -1;
		while (++j < size)
		{
				k = -1;
				while (++k < size)
				{
						index = i - ((size / 2) + j) + (size / 2 + k) * 800;
						if (index >= 0 && index < 800 * 500 && new[index] != 0)
								tot++;
				}
		}
		if (tot >= (size * size) / 2 - 2)
				return (WORMS_COLOR_DIRT);
		return (WORMS_COLOR_BACK);
}

int *w_antialiasing(int *perlin, int size)
{
		int *new;
		int i;

		new = (int*)ft_memalloc(sizeof(int) * (800 * 500));
		i = -1;
		while (++i < 800 * 500)
				new[i] = kernel_antialiasing(perlin, size, i);
		free(perlin);
		return (new);
}
