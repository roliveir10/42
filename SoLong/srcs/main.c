#include <sys/errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "solong.h"

void	exit_solong(int error, char *file, char *error_msg, void **data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("so_long: ", 2);
	if (file)
	{
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
	}
	errno = error;
	if (error > 0)
		perror(NULL);
	else
		ft_putstr_fd(error_msg, 2);
	if (data)
	{
		free(*data);
		*data = NULL;
	}
	while (1);
	exit(errno);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (argc != 2)
		exit_solong(0, NULL, "usage: ./so_long [file.ber]\n", NULL);
	ret = so_long(argv[1]);
	while (1);
	return (ret);
}
