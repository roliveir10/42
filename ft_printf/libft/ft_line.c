#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"

static char	*iso_line(char **isread, char c)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = *isread;
	while (tmp[i] && tmp[i] != c)
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

char	*ft_line(int fd, char c)
{
	char		buffer[BUFF_SIZE + 1];
	static char	*isread = NULL;
	int			ret;

	ret = 1;
	if (fd < 0 || fd > 256 || BUFF_SIZE < 1)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret < 1)
			break ;
		if (!isread)
			isread = (char *)ft_calloc(1, sizeof(char));
		buffer[ret] = 0;
		isread = ft_strjoinf(&isread, buffer);
		if (ft_strchr(isread, c))
			return (iso_line(&isread, c));
	}
	if (ret < 1 && !isread)
		return (NULL);
	return (iso_line(&isread, c));
}
