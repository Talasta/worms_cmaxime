#include "worms.h"

int *w_map_shape(int *perlin)
{
  int  i;
  int  ox;
  int  oy;
  int pos;

  i = -1;
  ox = 100;
  oy = 200;
  while (++i < 200 * 50)
  {
    pos = i + ox + 2 * ox * (i / 200) + oy * 400;
    perlin[pos] = WORMS_RED;
  }
  return (perlin);
}

int  *w_fill(int *perlin, int i, int color)
{
  perlin[i] = color;
  if ((i + 1) % 400 != 0 &&  i + 1 < 400 * 250 && perlin[i + 1] == 0)
    perlin = w_fill(perlin, i + 1, color);
  if (i % 400 != 0 && i - 1 > 0 && perlin[i - 1] == 0)
    perlin = w_fill(perlin, i - 1, color);
  if (i - 400 > 0 && perlin[i - 400] == 0)
    perlin = w_fill(perlin, i - 400, color);
  if (i + 400 < 400 * 250 && perlin[i + 400] == 0)
    perlin = w_fill(perlin, i + 400, color);
  return (perlin);
}

int  *w_flood_fill(int *perlin)
{
  int i;
  int pos;

  i = -1;
  while (++i < 50)
  {
    pos = 200 * 400 + 400 * i + 99;
    perlin = w_fill(perlin, pos, WORMS_RED);
  }
  i = -1;
  while (++i < 200)
  {
    pos = 199 * 400 + 100 + i;
    perlin = w_fill(perlin, pos, WORMS_RED);
  }
  i = -1;
  while (++i < 50)
  {
    pos = 200 * 400 + 400 * i + 300;
    perlin = w_fill(perlin, pos, WORMS_RED);
  }
  return (perlin);
}

int *w_clean_map(int *perlin)
{
  int i;

  i = -1;
  while (++i < 400 * 250)
  {
    if (perlin[i] == WORMS_WHITE)
      perlin[i] = 0;
  }
  return (perlin);
}
