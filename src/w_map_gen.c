#include "worms.h"

int  *w_map_gen(int type)
{
  int *perlin;

  (void)type;
  perlin = w_perlin_noise();
  perlin = w_map_shape(perlin);
  perlin = w_flood_fill(perlin);
  perlin = w_clean_map(perlin);
  perlin = w_kernel_fill(perlin, 4);
  perlin = w_fill(perlin, 0, WORMS_GREEN);
  perlin = w_clean_holes(perlin);
  perlin = w_erosion_clean(perlin, 4);
  perlin = w_fill(perlin, 0, WORMS_GREEN);
  perlin = w_clean_holes(perlin);
  perlin = w_scale_map(perlin);
  perlin = w_antialiasing(perlin, 4);
  perlin = w_grass(perlin, 7);
  return perlin;
}
