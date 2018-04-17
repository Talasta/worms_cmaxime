#include "worms.h"

int *kernel_grass(int *new, int size, int i)
{
  int j;

  if (new[i] == WORMS_COLOR_DIRT && i > 800 && i < 800 * 499 && new[i - 800] == WORMS_COLOR_BACK)
  {
    j = -1;
    while (++j < size)
    {
      if (i + j * 800 < 800 * 500)
        new[i + j * 800] = WORMS_COLOR_GRASS;
    }
  }
  return (new);
}

int *w_grass(int *new, int size)
{
  int i;
  int *texture;

  i = -1;
  while (++i < 800 * 500)
  {
    new = kernel_grass(new, size, i);
  }
  texture = w_get_perlin_texture();
  i = -1;
  while (++i < 800 * 500)
  {
    if (texture[i] == 0 && new[i] == WORMS_COLOR_DIRT)
      new[i] = WORMS_COLOR_TEXTURE;
  }
  free(texture);
  return (new);
}
