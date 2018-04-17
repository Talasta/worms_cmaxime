#include "worms.h"

t_img	circle(t_img img, int obx, int oby, int radius)
{
	int			x;
	int			y;
	int			a;
	double		rad;
	int			i;

	a = 0;
	while (a < 180)
	{
		rad = (double)a * M_PI / 180.0;
		x = (int)(cos(rad) * (double)radius) + obx;
		y = (int)(sin(rad) * (double)radius) + oby;
		i = (int)(sin((double)(360 - a) * M_PI / 180.0) * (double)radius) + oby;
		while (i <= y)
		{
			img = set_img_pxl(img, x, i, 0x00ff0000);
			i++;
		}
		a++;
	}
	return (img);
}
