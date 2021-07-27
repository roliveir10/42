#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_filedup(int fd, int *size)
{
	int		ret;
	char	buffer[BUFF_SIZE];
	char	*str;

	ret = 1;
	*size = 0;
	str = (char *)ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFF_SIZE - 1);
		if (ret < 1)
			break ;
		buffer[ret] = '\0';
		str = ft_strjoinf(&str, buffer);
		*size += ret;
	}
	return (str);
}
