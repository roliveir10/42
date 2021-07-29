#include <stdlib.h>
#include "solong.h"

int	solong_close(void *d)
{
	t_env	*env;

	env = (t_env *)d;
	solong_mlx_destroy(&env->mlx);
	ft_strdel(&env->map.map);
	exit(0);
	return (0);
}

int	solong_keypress(int keycode, void *d)
{
	const int	key[MAX_KEY] = {KESCAP, KW, KS, KA, KD};
	t_env		*env;
	int			i;

	env = (t_env *)d;
	if (keycode == KESCAP)
		return (solong_close((void *)env));
	i = -1;
	while (++i < MAX_KEY)
		if (key[i] == keycode)
			return (player_move(env, keycode));
	return (0);
}
