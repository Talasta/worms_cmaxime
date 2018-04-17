#include "worms.h"

int *set_kernel(int *map, int i, int color)
{
  if (i < 400 * 250 && i >= 0)
    map[i] = color;
  return (map);
}

int *kernel_indice(int *new, int size, int i, int color)
{
  int j;
  int k;

  j = -1;
  while (++j < size)
  {
    k = -1;
    while (++k < size)
    {
      if ((k != 0 || j!= 0) && (k != 0 || j!= 0) && (k != 0 || j!= 0) && (k != 0 || j!= 0))
        new = set_kernel(new, i - ((size / 2) + j) + (size / 2 + k) * 400, color);
    }
  }
  return (new);
}

int *w_kernel_fill(int *perlin, int size)
{
  int *new;
  int i;

  new = (int*)ft_memalloc(sizeof(int) * (400 * 250));
  i = -1;
  while (++i < 400 * 250)
  {
    if (perlin[i] == WORMS_RED)
      new = kernel_indice(new, size, i, WORMS_RED);
  }
  free(perlin);
  return (new);
}

int *w_clean_holes(int *perlin)
{
  int i;

  i = -1;
  while (++i < 400 * 250)
  {
    if (perlin[i] == 0)
      perlin[i] = WORMS_RED;
  }
  i = -1;
  while (++i < 400 * 250)
  {
    if (perlin[i] == WORMS_GREEN)
      perlin[i] = 0;
  }
  return (perlin);
}
