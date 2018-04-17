#ifndef STC_WORMS_H
# define STC_WORMS_H

# include "libft.h"

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		endian;
	int		size_line;
	int		size_column;
	int		bpp;
}				t_img;

typedef struct	s_object
{
	double x;
	double y;
	double m;
	double vx;
	double vy;
	int ori;
	int type;
	//char *type;
	//void *strct;
}								t_object;

typedef struct	s_cnf
{
	int		*map;
	unsigned int		time;
	t_list	*object;
}				t_cnf;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_cnf		cnf;
	t_img		img;
}				t_mlx;


#endif
