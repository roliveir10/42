#include "libft.h"

t_vector3	ft_vdot_to_vector3(t_vector3 pos_a, t_vector3 pos_b)
{
	return (ft_vnormalize(ft_vsub(pos_a, pos_b)));
}
