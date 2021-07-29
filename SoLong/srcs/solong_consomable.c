#include "solong.h"

int	end_point2d(t_map *map)
{
	int			i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == END)
			return ((i / map->size.x) * map->size.x + i % map->size.x);
		i++;
	}
	return (0);
}

int	conso_total(char *map)
{
	int	i;
	int	conso;

	i = 0;
	conso = 0;
	while (map[i])
	{
		if (map[i] == CONSO)
			conso++;
		i++;
	}
	return (conso);
}
