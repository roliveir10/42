#include "libft.h"

t_vector3	ft_vcross(t_vector3 v1, t_vector3 v2)
{
	t_vector3	result;

	result.x = v1.y * v2.z - v2.y * v1.z;
	result.y = v1.z * v2.x - v2.z * v1.x;
	result.z = v1.x * v2.y - v2.x * v1.y;
	return (result);
}
