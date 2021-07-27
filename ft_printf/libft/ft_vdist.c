#include "libft.h"

double	ft_vdist(t_vector3 v1, t_vector3 v2)
{
	t_vector3	vc;

	vc = ft_vsub(v1, v2);
	return (ft_sqrt(ft_pow(vc.x, 2) + ft_pow(vc.y, 2) + ft_pow(vc.z, 2)));
}
