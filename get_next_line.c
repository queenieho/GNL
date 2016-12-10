/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:50:55 by qho               #+#    #+#             */
/*   Updated: 2016/12/10 00:55:58 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	char buf[BUFF_SIZE];

	while (read(fd, &buf, BUFF_SIZE))
		ft_putstr(buf);
	return (0);
}
