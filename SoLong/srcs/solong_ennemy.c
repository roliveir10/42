#include <stdlib.h>
#include "solong.h"

void	ennemy_clear_list(void *data)
{
	ft_memdel((void **)&data);
}

t_list	*ennemy_list(t_map *map)
{
	t_list		*new;
	t_ennemy	*e;
	int			i;

	i = 0;
	new = NULL;
	while (map->map[i])
	{
		if (map->map[i] == ENHOR || map->map[i] == ENVER)
		{
			e = (t_ennemy *)malloc(sizeof(t_ennemy));
			if (e == NULL)
				return (NULL);
			e->pos = (i / map->size.x) * map->size.x + i % map->size.x;
			e->move = 1;
			if (map->map[i] == ENVER)
				e->move = map->size.x;
			e->dir = map->map[i];
			ft_list_push_front(&new, (void *)e);
		}
		i++;
	}
	return (new);
}

static int	ennemy_check_move(t_map *map, int newpos)
{
	if (newpos < 0 || newpos >= map->size.x * map->size.y)
		return (0);
	if (ft_strchr("0P", map->map[newpos]))
		return (1);
	return (0);
}

static int	ennemy_move_direction(t_map *map, int newpos, t_ennemy *e)
{
	int	ret;

	ret = ennemy_check_move(map, newpos);
	if (ret)
	{
		map->map[e->pos] = EMPTY;
		e->pos = newpos;
		map->map[e->pos] = e->dir;
	}
	return (ret);
}

void	ennemy_move(t_env *env)
{
	t_list		*list;
	t_ennemy	*e;
	t_point2d	epos;
	t_point2d	ppos;
	int			ret;

	list = env->game.ennemy;
	ppos = pos_to_point2d(env->p.pos, env->map.size);
	while (list)
	{
		e = (t_ennemy *)list->data;
		epos = pos_to_point2d(e->pos, env->map.size);
		ret = ennemy_move_direction(&env->map, e->pos + e->move, e);
		if (ret == 0)
		{
			e->move = -e->move;
			ennemy_move_direction(&env->map, e->pos + e->move, e);
		}	
		if (e->pos == env->p.pos)
			game_over((void *)env);
		list = list->next;
	}
}
