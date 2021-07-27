#include "libft.h"

t_vector3	ft_vmul(t_vector3 v, double f)
{
	t_vector3	result;

	result.x = v.x * f;
	result.y = v.y * f;
	result.z = v.z * f;
	return (result);
}
