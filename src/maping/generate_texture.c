#include "worms.h"

int *w_get_perlin_texture(void)
{
  int i;
  int buff;
  int *perlin;
  int k;

  i = -1;
  srand(time(NULL));
  k = rand() % 256;
  perlin = (int*)malloc(sizeof(int) * (800 * 500));
  while (++i < 800 * 500)
  {
    buff = (int)((Get2DPerlinNoiseValue((float)(i % 800) + 0.5
    , (float)(i / 800) + 0.5, 25.0, k) + 1) * 0.5 * 255);
    perlin[i] = buff > 160 ? 0 : 255;
    perlin[i] = (perlin[i] | (perlin[i] << 8)) | (perlin[i] << 16);
  }
  return perlin;
}
