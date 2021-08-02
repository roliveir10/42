#include "solong.h"

t_point2d	point2d_to_pos(t_point2d p, t_point2d size)
{
	t_point2d	p2d;

	p2d.x = p.x % size.x;
	p2d.y = p.y / size.x;
	return (p2d);
}

t_point2d	pos_to_point2d(int pos, t_point2d size)
{
	t_point2d	p2d;

	p2d.x = pos % size.x;
	p2d.y = pos / size.x;
	return (p2d);
}

int	pix_to_tile(int pos, t_point2d size, t_point2d screen)
{
	int		tile_x;
	int		tile_y;

	tile_x = (pos % screen.x) * size.x / screen.x;
	tile_y = (pos / screen.x) * size.y / screen.y;
	return (tile_y * size.x + tile_x);
}
