#include "libft.h"

t_vector3	ft_vdiv(t_vector3 v, double f)
{
	t_vector3	result;

	if (!f)
	{
		ft_bzero(&result, sizeof(t_vector3));
		return (result);
	}
	result.x = v.x / f;
	result.y = v.y / f;
	result.z = v.z / f;
	return (result);
}
