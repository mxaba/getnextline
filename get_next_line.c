/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:36:41 by mxaba             #+#    #+#             */
/*   Updated: 2018/06/18 13:09:10 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_readline(char **holder, char **line)
{
	char	*temp;

	if ((*holder)[0] == '\0')
		return (0);
	if (ft_strchr(*holder, '\n') != NULL)
	{
		*(ft_strchr(*holder, '\n')) = '\0';
		*line = ft_strdup(*holder);
		temp = ft_strdup(ft_strchr(*holder, '\0') + 1);
		free(*holder);
		if (temp)
		{
			*holder = ft_strdup(temp);
			free(temp);
		}
	}
	else
	{
		*line = ft_strdup(*holder);
		ft_memdel((void **)holder);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int				br;
	char			buf[BUFF_SIZE + 1];
	static char		*array[FD_LIMIT];
	char			*temp;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == 0)
		return (-1);
	if (!(array[fd]))
		array[fd] = ft_strnew(0);
	while (ft_strchr(array[fd], '\n') == NULL)
	{
		br = read(fd, buf, BUFF_SIZE);
		buf[br] = '\0';
		if (br == 0)
			break ;
		temp = ft_strjoin(array[fd], buf);
		free(array[fd]);
		array[fd] = ft_strdup(temp);
		if (!(array[fd]))
			array[fd] = ft_strnew(0);
		free(temp);
	}
	return (ft_readline(&array[fd], line));
}
