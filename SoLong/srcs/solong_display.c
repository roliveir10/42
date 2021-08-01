#include "mlx.h"
#include "solong.h"

/*static int	solong_map_texture(char *map, int map_tile)
{
	const int	color[MAP_CHAR_MAX] = {0x096b41, 0xffffff, 0xe4d113, 0x144628,
		0xcc3b56, 0x282814, 0x282814};
	const char	map_char[MAP_CHAR_MAX] = "01CEP-|";
	int			i;

	i = -1;
	while (++i < MAP_CHAR_MAX)
		if (map[map_tile] == map_char[i])
			return (color[i]);
	return (0xffffff);
}
*/
static int	pix_to_tile(int pos, t_point2d map_size, t_point2d screen)
{
	int	tile_x;
	int	tile_y;

	tile_x = (pos % screen.x) * map_size.x / screen.x;
	tile_y = (pos / screen.x) * map_size.y / screen.y;
	return (tile_y * map_size.x + tile_x);
}

static void	display_move_count(t_mlx *mlx, int move_count)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(move_count);
	if (!tmp)
		return ;
	str = ft_strjoin("Move count: ", tmp);
	if (str)
		mlx_string_put(mlx->mlx, mlx->win, 15, 15,
			COUNT_MOVE_COLOR, str);
	ft_strdel(&tmp);
	if (str)
		ft_strdel(&str);
}

#include <stdio.h>

void	solong_display(t_env *env)
{
	int		pix_i;
	int		map_tile;
	int		color;

	pix_i = 0;
	while (pix_i < env->mlx.screen.x * env->mlx.screen.y)
	{
		map_tile = pix_to_tile(pix_i, env->map.size, env->mlx.screen);
		color = pix_to_textures(env, env->map.map[map_tile], pix_i);
		solong_img_write(&env->mlx.img, pix_i % env->mlx.screen.x,
				pix_i / env->mlx.screen.x, color);
		pix_i++;
	}
	mlx_put_image_to_window(env->mlx.mlx, env->mlx.win, env->mlx.img.img, 0, 0);
	display_move_count(&env->mlx, env->game.move);
}
