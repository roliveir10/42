#include "libft.h"

double	ft_vdot(t_vector3 va, t_vector3 vb)
{
	return (va.x * vb.x + va.y * vb.y + va.z * vb.z);
}
