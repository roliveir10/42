#include "libft.h"

t_vector3	ft_vsub(t_vector3 pos_a, t_vector3 pos_b)
{
	t_vector3	result;

	result.x = pos_b.x - pos_a.x;
	result.y = pos_b.y - pos_a.y;
	result.z = pos_b.z - pos_a.z;
	return (result);
}
