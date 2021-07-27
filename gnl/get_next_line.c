#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

char	*ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

static char	*iso_line(char **isread)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = *isread;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i])
	{
		line = ft_substr(tmp, 0, i + 1);
		ft_strlcpy(tmp, &tmp[i + 1], ft_strlen(tmp) + 1);
		if (tmp[0] == 0)
			ft_strdel(isread);
		return (line);
	}
	line = ft_substr(tmp, 0, i);
	ft_strdel(isread);
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*isread = NULL;
	int			ret;

	ret = 1;
	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 1)
			break ;
		if (!isread)
		{
			isread = (char *)malloc(sizeof(char));
			*isread = 0;
		}
		buffer[ret] = 0;
		isread = ft_strjoinf(&isread, buffer);
		if (ft_strchr(isread, '\n'))
			return (iso_line(&isread));
	}
	if (ret < 1 && !isread)
		return (NULL);
	return (iso_line(&isread));
}
