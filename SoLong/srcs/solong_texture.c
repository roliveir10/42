#include "solong.h"
#include "mlx.h"

int	textures_load(t_mlx *mlx, t_texture t[T_MAX])
{
	char	*txlist[T_MAX] = {"./textures/ground.xpm", "./textures/conso.xpm",
		"./textures/character.xpm", "./textures/rock.xpm", "./textures/ennemy.xpm", "./textures/end.xpm"};
	int		i;

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

static unsigned int	tile_to_texture(t_point2d te_size, int pix_i, t_point2d screen, t_point2d ti_size)
{
	int	x;
	int	y;

	x = pix_i % screen.x;
	y = pix_i / screen.x;

	x = x % ti_size.x;
	y = y % ti_size.y;
	x = x * te_size.x / ti_size.x;
	y = y * te_size.y / ti_size.y;
	return (y * te_size.x + x);
}

unsigned int	pix_to_textures(t_env *env, char c, int pix_i)
{
	unsigned int	tbg;
	unsigned int	tfg;
	t_point2d		ti_size;

	ti_size.x = env->mlx.screen.x / env->map.size.x;
	ti_size.y = env->mlx.screen.y / env->map.size.y;
	tbg = tile_to_texture(env->t[0].size, pix_i, env->mlx.screen, ti_size);
	if (c == WALL)
	{
		tfg = tile_to_texture(env->t[3].size, pix_i, env->mlx.screen, ti_size);
		if (env->t[3].img.addr[tfg] != 0xFF000000)
			return (env->t[3].img.addr[tfg]);
	}
	else if (c == CONSO)
	{
		tfg = tile_to_texture(env->t[1].size, pix_i, env->mlx.screen, ti_size);
		if (env->t[1].img.addr[tfg] != 0xFF000000)
			return (env->t[1].img.addr[tfg]);
	}
	else if (c == PLAYER)
	{
		tfg = tile_to_texture(env->t[2].size, pix_i, env->mlx.screen, ti_size);
		if (env->t[2].img.addr[tfg] != 0xFF000000)
			return (env->t[2].img.addr[tfg]);
	}
	else if (c == ENHOR || c == ENVER)
	{
		tfg = tile_to_texture(env->t[4].size, pix_i, env->mlx.screen, ti_size);
		if (env->t[4].img.addr[tfg] != 0xFF000000)
			return (env->t[4].img.addr[tfg]);
	}
	else if (c == END)
	{
		tfg = tile_to_texture(env->t[5].size, pix_i, env->mlx.screen, ti_size);
		if (env->t[5].img.addr[tfg] != 0xFF000000)
			return (env->t[5].img.addr[tfg]);
	}
	return (env->t[0].img.addr[tbg]);
}
