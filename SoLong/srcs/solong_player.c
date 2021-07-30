#include "solong.h"

static int	player_check_move(t_map *map, int newpos)
{
	if (newpos < 0 || newpos >= map->size.x * map->size.y)
		return (-1);
	if (ft_strchr("0CE-|", map->map[newpos]))
		return (1);
	return (-1);
}

static void	player_update_game(t_map *map, t_game *game, t_player *p)
{
	if (map->map[p->pos] == CONSO)
		game->conso--;
	if (map->map[p->pos] == END && game->conso == 0)
		game->win = 1;
	if (map->map[p->pos] == ENVER || map->map[p->pos] == ENHOR)
		game->lose = 1;
	game->move++;
	ft_putnbrl(game->move);
	map->map[p->pos] = PLAYER;
}

int	player_move(t_env *env, int keycode)
{
	const int	key[4] = {KW, KS, KA, KD};
	const int	inc[4] = {-env->map.size.x, env->map.size.x, -1, 1};
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (ret == 0 && ++i < 4)
		if (key[i] == keycode)
			ret = player_check_move(&env->map, env->p.pos + inc[i]);
	if (ret == -1 || i == 4)
		return (0);
	env->map.map[env->p.pos] = EMPTY;
	if (env->p.pos == env->game.pos_end)
		env->map.map[env->p.pos] = END;
	env->p.pos += inc[i];
	player_update_game(&env->map, &env->game, &env->p);
	if (env->game.win == 1)
		game_win((void *)env);
	if (env->game.lose == 1)
		game_over((void *)env);
	ennemy_move(env);
	solong_display(&env->mlx, &env->map);
	return (1);
}

int	player_valid_in_map(t_player *p, t_map *map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == PLAYER)
		{
			p->pos = (i / map->size.x) * map->size.x + i % map->size.x;
			count++;
		}
		i++;
	}
	return (count == 1);
}
