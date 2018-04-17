#include "worms.h"

int kernel_erosion(int *new, int size, int i)
{
  int j;
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
      if ((k != 0 || j!= 0) && (k != 0 || j!= 0) && (k != 0 || j!= 0) && (k != 0 || j!= 0))
      {
        index = i - ((size / 2) + j) + (size / 2 + k) * 400;
        if (index >= 0 && index < 400 * 250 && new[index] != 0)
          tot++;
      }
    }
  }
  if (tot >= (size * size) / 2 - 2)
    return (WORMS_RED);
  return (0);
}

int *w_erosion_clean(int *perlin, int size)
{
  int *new;
  int i;

  new = (int*)ft_memalloc(sizeof(int) * (400 * 250));
  i = -1;
  while (++i < 400 * 250)
      new[i] = kernel_erosion(perlin, size, i);
  free(perlin);
  return (new);
}
