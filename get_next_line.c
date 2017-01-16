/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:33:20 by qho               #+#    #+#             */
/*   Updated: 2017/01/16 15:31:40 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_line(char **line, char **hold, char *buf)
{
	char		*tmp;

	if (buf)
	{
		if (*hold)
			*hold = ft_strjoin(*hold, buf);
		else
			*hold = ft_strdup(buf);
	}
	if ((tmp = ft_strchr(*hold, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*hold);
		tmp++;
		free(*hold);
		*hold = ft_strdup(tmp);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*hold = NULL;
	char		*buf;
	int			ret;

	if (fd < 0 || (size_t)&*line == 0)
		return (-1);
	if (hold && (ft_get_line(line, &hold, NULL)))
		return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (ft_get_line(line, &hold, buf))
			return (1);
	}
	if (hold && *hold != '\0' && (*line = ft_strdup(hold)))
	{
		free(hold);
		hold = 0;
		return (1);
	}
	hold = 0;
	return (0);
}
