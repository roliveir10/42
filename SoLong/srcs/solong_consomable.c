#include "solong.h"

int	end_point2d(int *pos_end, t_map *map)
{
	int			i;
	int			end;

	i = 0;
	end = 0;
	while (map->map[i])
	{
		if (map->map[i] == END)
		{
			end++;
			*pos_end = (i / map->size.x) * map->size.x + i % map->size.x;
		}
		i++;
	}
	return (end == 1);
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
