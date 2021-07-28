#include <sys/errno.h>
#include "solong.h"

void	check_file_format(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i < 4 || ft_strcmp(&file[i - 4], ".ber"))
		exit_solong(EFTYPE, file, NULL, NULL);
}

int	so_long(char *file)
{
	t_env	env;

	check_file_format(file);
	ft_bzero(&env, sizeof(t_env));
	env.map.map = file_to_map(file, &env.map.width, &env.map.height);
	if (env.map.map == NULL)
		exit_solong(errno, file, NULL, NULL);
	ft_strdel(&env.map.map);
	return (0);
}
