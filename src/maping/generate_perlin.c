#include "worms.h"

int *w_get_perlin(void)
{
  int i;
  int buff;
  int *perlin;
  int k;

  i = -1;
  srand(time(NULL));
  k = rand() % 256;
  perlin = (int*)malloc(sizeof(int) * (400 * 250));
  while (++i < 400 * 250)
  {
    buff = (int)((Get2DPerlinNoiseValue((float)(i % 400) + 0.5
    , (float)(i / 400) + 0.5, 25.0, k) + 1) * 0.5 * 255);
    perlin[i] = buff > 128 ? 0 : 255;
    perlin[i] = (perlin[i] | (perlin[i] << 8)) | (perlin[i] << 16);
  }
  return perlin;
}

int *w_map_shape2(int *perlin)
{
  int  i;
  int  ox;
  int  oy;
  int pos;

  i = -1;
  ox = 60;
  oy = 150;
  while (++i < 280 * 100)
  {
    pos = i + ox + 2 * ox * (i / 280) + oy * 400;
    perlin[pos] = WORMS_GREEN;
  }
  return (perlin);
}

int *w_get_perlin2(void)
{
  int i;
  int buff;
  int *perlin;
  int k;

  i = -1;
  srand(time(NULL));
  k = rand() % 256;
  perlin = (int*)ft_memalloc(sizeof(int) * (400 * 250));
  perlin = w_map_shape2(perlin);
  while (++i < 400 * 250)
  {
    if (perlin[i] != WORMS_GREEN)
    {
      buff = (int)((Get2DPerlinNoiseValue((float)(i % 400) + 0.5
      , (float)(i / 400) + 0.5, 10.0, k) + 1) * 0.5 * 255);
      perlin[i] = buff > 128 ? 0 : 255;
      perlin[i] = (perlin[i] | (perlin[i] << 8)) | (perlin[i] << 16);
    }
  }
  return perlin;
}

int *w_perlin_noise(void)
{
  int *perlin1;
  int *perlin2;
  int i;

  perlin1 = w_get_perlin();
  perlin2 = w_get_perlin2();
  i = -1;
  while (++i < 400 * 250)
  {
    if (perlin2[i] == WORMS_WHITE)
      perlin1[i] = WORMS_WHITE;
  }
  free(perlin2);
  return (perlin1);
}
