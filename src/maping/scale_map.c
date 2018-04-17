#include "worms.h"

int *w_scale_map(int *perlin)
{
  int *new;
  int i;

  new = (int*)ft_memalloc(sizeof(int) * (800 * 500));
  i = -1;
  while (++i < 400 * 250)
  {
    new[i * 2 + (i / 400) * 800] = perlin[i];
    new[i * 2 + 1 + (i / 400) * 800] = perlin[i];
    new[i * 2 + (i / 400) * 800 + 800] = perlin[i];
    new[i * 2 + 1 + (i / 400) * 800 + 800] = perlin[i];
  }
  free(perlin);
  return (new);
}
