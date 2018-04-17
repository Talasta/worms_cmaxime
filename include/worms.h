#ifndef WORMS_H
# define WORMS_H

# include <mlx.h>
# include <math.h>
# include <time.h>
# include <sys/timeb.h>
# include "libft.h"
# include "stc_worms.h"
# include <fcntl.h>

# define WORMS_G 9.80665
# define WORMS_F 1.002
# define ABSORBANCE_T 2.5
# define WORMS_WIND -0.005

# define WORMS_COLOR_BACK 0x00b6fcff
# define WORMS_COLOR_DIRT 0x00896301
# define WORMS_COLOR_TEXTURE 0x00764d00
# define WORMS_COLOR_GRASS 0x0040a623

# define WORMS_WHITE 0x00ffffff
# define WORMS_RED 0x00ff0000
# define WORMS_GREEN 0x0000ff00

/*
** MAP GENERATION FCTS
**/
int		*w_perlin_noise(void);
int		*w_map_shape(int *perlin);
int		*w_flood_fill(int *perlin);
int		*w_clean_map(int *perlin);
int		*w_kernel_fill(int *perlin, int size);
int		*w_fill(int *perlin, int i, int color);
int		*w_clean_holes(int *perlin);
int		*w_erosion_clean(int *perlin, int size);
int		*w_scale_map(int *perlin);
int		*w_antialiasing(int *perlin, int size);
int		*w_grass(int *new, int size);
int		*w_get_perlin_texture(void);
/**/

/*
** WINDOW CONTROLS FCTS
**/
int		refresh(void *param);
int		actions(int key_hook, void *param);
int		mouse_on(int button, int x, int y, void *param);
int		mouse(int button, int x, int y, void *param);
int		drag_drop(int x, int y, void *param);
/**/

t_list	*get_worm(t_list *object);

int		get_pxl_val(int *img, int x, int y);

t_mlx	w_image_drawer(t_mlx mlx);
t_mlx	w_image_drawer2(t_mlx mlx);
t_img	circle(t_img img, int obx, int oby, int radius);
t_img	set_img_pxl(t_img img, int x, int y, int color);

int		*w_map_gen(int type);
float	Get2DPerlinNoiseValue(float x, float y, float res, int k);

#endif
