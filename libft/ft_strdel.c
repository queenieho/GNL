/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 17:18:48 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 13:54:47 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (as == NULL)
		return ;
	while (*as[i])
	{
		while (as[j])
		{
			free(as[j]);
			j++;
		}
		as = NULL;
		free((void *)as[i]);
		i++;
	}
	*as = NULL;
}
