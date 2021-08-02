#include "solong.h"
#include "mlx.h"

int	textures_load(t_mlx *mlx, t_texture t[T_MAX])
{
	static char	*txlist[T_MAX] = {"./textures/ground.xpm",
		"./textures/conso.xpm",
		"./textures/character.xpm",
		"./textures/rock.xpm",
		"./textures/ennemy.xpm",
		"./textures/end.xpm"};
	int			i;

	i = 0;
	while (i < T_MAX)
	{
		t[i].img.img = mlx_xpm_file_to_image(mlx->mlx, txlist[i],
				&t[i].size.x, &t[i].size.y);
		if (!t[i].img.img)
			return (0);
		t[i].img.addr = (unsigned int *)mlx_get_data_addr(t[i].img.img,
				&t[i].img.bpp, &t[i].img.size_line, &t[i].img.endian);
		if (!t[i].img.addr)
		{
			mlx_destroy_image(mlx->mlx, t[i].img.img);
			return (0);
		}
		i++;
	}
	return (1);
}

static unsigned int	tile_to_texture(t_point2d te_size, int pix_i,
		t_point2d screen, t_point2d ti_size)
{
	t_point2d	pos;

	pos = pos_to_point2d(pix_i, screen);
	pos.x = pos.x % ti_size.x;
	pos.y = pos.y % ti_size.y;
	pos.x = pos.x * te_size.x / ti_size.x;
	pos.y = pos.y * te_size.y / ti_size.y;
	return (pos.y * te_size.x + pos.x);
}

static unsigned int	texture_raycast(t_texture t, int pos, t_point2d screen,
		t_point2d ti_size)
{
	unsigned int	i;

	i = tile_to_texture(t.size, pos, screen, ti_size);
	return (t.img.addr[i]);
}

unsigned int	pix_to_textures(t_env *env, char c, int pix_i)
{
	unsigned int	tbg;
	unsigned int	tfg;
	t_point2d		ti_size;

	ti_size.x = env->mlx.screen.x / env->map.size.x;
	ti_size.y = env->mlx.screen.y / env->map.size.y;
	tbg = texture_raycast(env->t[0], pix_i, env->mlx.screen, ti_size);
	tfg = 0xFF000000;
	if (c == WALL)
		tfg = texture_raycast(env->t[3], pix_i, env->mlx.screen, ti_size);
	else if (c == CONSO)
		tfg = texture_raycast(env->t[1], pix_i, env->mlx.screen, ti_size);
	else if (c == PLAYER)
		tfg = texture_raycast(env->t[2], pix_i, env->mlx.screen, ti_size);
	else if (c == ENHOR || c == ENVER)
		tfg = texture_raycast(env->t[4], pix_i, env->mlx.screen, ti_size);
	else if (c == END)
		tfg = texture_raycast(env->t[5], pix_i, env->mlx.screen, ti_size);
	if (tfg == 0xFF000000)
		return (tbg);
	return (tfg);
}
