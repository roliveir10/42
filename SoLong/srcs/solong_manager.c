#include <sys/errno.h>
#include "solong.h"
#include "mlx.h"

static void	check_file_format(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4 || ft_strcmp(&file[i - 4], ".ber"))
		exit_solong(EFTYPE, file, NULL, NULL);
}

static void	set_up_win_size(t_mlx *mlx, t_point2d map_size)
{
	int	ratio;

	if (map_size.x > map_size.y)
		ratio = SCREENX_MAX / map_size.x;
	else
		ratio = SCREENY_MAX / map_size.y;
	mlx->screen.x = map_size.x * ratio;
	mlx->screen.y = map_size.y * ratio;
}

static void	so_long_setup(char *file, t_env *env)
{
	set_up_win_size(&env->mlx, env->map.size);
	if (env->map.map == NULL)
		exit_solong(errno, file, NULL, NULL);
	if (player_valid_in_map(&env->p, &env->map) == 0)
		exit_solong(0, file, "too many players in map\n", (void **)&env->map.map);
	env->game.conso = conso_total(env->map.map);
	if (end_point2d(&env->game.pos_end, &env->map) == 0)
		exit_solong(0, file, "too many end in map\n", (void **)&env->map.map);
	if (solong_mlx_initialize(&env->mlx) == 0)
		exit_solong(0, file, "mlx failed to run program\n", (void **)&env->map.map);
	env->game.ennemy = ennemy_list(&env->map);
}

int	so_long(char *file)
{
	t_env	env;

	check_file_format(file);
	ft_bzero(&env, sizeof(t_env));
	env.map.map = file_to_map(file, &env.map.size.x, &env.map.size.y);
	so_long_setup(file, &env);
	solong_display(&env.mlx, &env.map);
	mlx_hook(env.mlx.win, KEYPRESS, 0, solong_keypress, (void *)&env);
	mlx_hook(env.mlx.win, REDBUTTON, 0, solong_close, (void *)&env);
	mlx_loop(env.mlx.mlx);
	ft_strdel(&env.map.map);
	return (0);
}
