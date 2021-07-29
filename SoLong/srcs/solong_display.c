#include "mlx.h"
#include "solong.h"

static int	solong_map_texture(char *map, int map_tile)
{
	const int	color[MAP_CHAR_MAX] = {0x096b41, 0xffffff, 0xe4d113, 0x144628, 0xcc3b56};
	const char	map_char[MAP_CHAR_MAX] = "01CEP";
	int			i;

	i = -1;
	while (++i < MAP_CHAR_MAX)
		if (map[map_tile] == map_char[i])
			return (color[i]);
	return (0xffffff);
}

static int	pix_to_tile(int pos, t_point2d map_size, t_point2d screen)
{
	int	tile_x;
	int	tile_y;

	tile_x = (pos % screen.x) * map_size.x / screen.x;
	tile_y = (pos / screen.x) * map_size.y / screen.y;
	return (tile_y * map_size.x + tile_x);
}

void	solong_display(t_mlx *mlx, t_map *map)
{
	int		pix_i;
	int		map_tile;
	int		color;

	pix_i = 0;
	while (pix_i < mlx->screen.x * mlx->screen.y)
	{
		map_tile = pix_to_tile(pix_i, map->size, mlx->screen);
		color = solong_map_texture(map->map, map_tile);
		solong_img_write(&mlx->img, pix_i % mlx->screen.x, pix_i / mlx->screen.x, color);
		pix_i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
