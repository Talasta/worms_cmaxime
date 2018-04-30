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

/*
** ACTIONS CONTROLS FCTS
**/
int	  *set_map_pxl(int *map, int x, int y, int color);
void 	explode_map(t_mlx *mlx, t_object *obj);
void 	update_time_objects(t_list **object, t_mlx *mlx);
t_mlx throw_grenade(t_mlx mlx);
void update_gre_timer(t_mlx *mlx, int key_hook);
int check_slop(int *map, int x, int y);
void  move_worm(t_object *obj, double key, int *map);
t_mlx move_controls(t_mlx mlx, double key);
t_list *get_next_worm(t_list *curr, t_list *list);
void 	update_time_status(t_mlx *mlx);
void update_scope(t_mlx *mlx, int key_hook);
t_mlx jump(t_mlx mlx);
/**/

/*
** COLLISION CONTROLS FCTS
**/
unsigned char *get_collision_const(void);
unsigned char get_collision_mask(int x, int y, int *map);
int 	get_transpho(int x, int y, int *map);
void 	w_recalculate_speed(t_object *obj, int *map);
void 	w_update_objs(t_list *objects, int *map);
t_object 	*w_recalculate_y(t_object *obj, int *map);
/**/

/*
** TIMER CONTROLS FCTS
**/
void timer_print(t_list *list, t_mlx *mlx);
/**/

t_list	*get_worm(t_list *object);
void free_obj(t_list **object, t_list *elem);

int		get_pxl_val(int *img, int x, int y);

t_mlx	w_image_drawer(t_mlx mlx);
t_mlx	w_image_drawer2(t_mlx mlx);
t_img	circle(t_img img, int obx, int oby, int radius);
t_img	set_img_pxl(t_img img, int x, int y, int color);

int		*w_map_gen(int type);
float	Get2DPerlinNoiseValue(float x, float y, float res, int k);

#endif
