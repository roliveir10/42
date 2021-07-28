#include "libft.h"

t_vector3	ft_normalize(t_vector3 v)
{
	double	r;

	r = ft_sqrt(ft_pow(v.x, 2) + ft_pow(v.y, 2) + ft_pow(v.z, 2));
	return (ft_vdiv(v, r));
}
