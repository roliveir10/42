#include "mlx.h"
#include "solong.h"

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
