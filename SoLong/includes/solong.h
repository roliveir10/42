#ifndef SOLONG_H
# define SOLONG_H

# include "libft.h"

# define MAP_CHAR "01CEP"

typedef struct s_map
{
	char	*map;
	int		width;
	int		height;
}	t_map;

typedef struct s_env
{
	t_map	map;
}	t_env;

int		so_long(char *file);
char	*file_to_map(char *file, int *width, int *height);
void	exit_solong(int error, char *file, char *error_msg, void **data);
#endif
