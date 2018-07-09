/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mxaba <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:17:53 by mxaba             #+#    #+#             */
/*   Updated: 2018/06/19 09:49:53 by mxaba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	if (argc < 2)
		ft_putstr("error");
}
