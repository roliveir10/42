#include "solong.h"
#include "mlx.h"

int	solong_mlx_destroy(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->mlx, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int	solong_mlx_initialize(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, mlx->screen.x,
			mlx->screen.y, WIN_TITLE);
	if (!mlx->win)
		return (0);
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->screen.x, mlx->screen.y);
	if (!mlx->img.img)
		return (solong_mlx_destroy(mlx));
	mlx->img.addr = (unsigned int *)mlx_get_data_addr(mlx->img.img,
			&mlx->img.bpp, &mlx->img.size_line, &mlx->img.endian);
	if (!mlx->img.addr)
		return (solong_mlx_destroy(mlx));
	mlx->img.size_line /= 4;
	return (1);
}

void	solong_img_write(t_img *img, int x, int y, int color)
{
	img->addr[y * img->size_line + x] = color;
}
