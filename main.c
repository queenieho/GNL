/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:58:10 by qho               #+#    #+#             */
/*   Updated: 2016/12/10 00:39:05 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int ac, char **av)
{
	int fd;
	int i;
	char *line;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			while (get_next_line(fd, &line))
				ft_putstr(line);
			i++;
		}
	}
	return (0);
}