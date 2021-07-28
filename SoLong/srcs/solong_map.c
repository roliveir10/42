#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "solong.h"

static int	line_validity(char *line, int width)
{
	int	i;

	i = 0;
	if (*line != '1')
		return (0);
	while (i < width - 1)
	{
		if (!line[i] || line[i] == '\n')
			return (0);
		if (!ft_strchr(MAP_CHAR, line[i]))
			return (0);
		i++;
	}
	if (line[i] != '1')
		return (0);
	i++;
	return (line[i] == 0 || line[i] == '\n');
}

static int	get_map_width(int fd, char *file, char **map)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_line(fd, '\n');
	if (!line || !*map)
		exit_solong(0, file, "1parsing error\n", (void **)map);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			ft_strdel(&line);
			exit_solong(0, file, "1.5parsing error\n", (void **)map);
		}
		i++;
	}
	if (i > 0 && line_validity(line, i) == 1)
	{
		*map = ft_strnjoinf(map, line, 0, i);
		ft_strdel(&line);
		return (i);
	}
	ft_strdel(&line);
	exit_solong(0, file, "2parsing error\n", (void **)map);
	return (-1);
}

static char	*map_validity(char **map, char *file, int width, int height)
{
	int				i;
	unsigned int	bit_char;
	char			lst_char[128];

	if (!*map)
		return (NULL);
	i = height * (width - 1);
	while (i < width * height)
	{
		if ((*map)[i] != '1')
			exit_solong(0, file, "3parsing error\n", (void **)map);
		i++;
	}
	ft_bzero(lst_char, 128);
	lst_char['C'] = 1;
	lst_char['E'] = 2;
	lst_char['P'] = 4;
	i = -1;
	bit_char = 0;
	while (++i < width * height)
		bit_char |= lst_char[(unsigned char)(*map)[i]];
	if (bit_char != 7)
		exit_solong(0, file, "map must have at least [C] [E] [P]\n", (void **)map);
	return (*map);
}

char	*file_to_map(char *file, int *width, int *height)
{
	int		fd;
	char	*line;
	int		ret;
	char	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_solong(errno, file, NULL, NULL);
	map = (char *)ft_calloc(1, sizeof(char));
	*width = get_map_width(fd, file, &map);
	*height = 1;
	while (map)
	{
		line = ft_line(fd, '\n');
		if (!line)
			break ;
		ret = line_validity(line, *width);
		map = ft_strnjoinf(&map, line, ft_strlen(map), *width);
		ft_strdel(&line);
		if (ret == 0)
			exit_solong(0, file, "4parsing error\n", (void **)&map);
		*height += 1;
	}
	close(fd);
	return (map_validity(&map, file, *width, *height));
}
