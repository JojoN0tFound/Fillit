/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:37:35 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 17:24:18 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

t_vector	*ft_get_vector(int x, int y)
{
	t_vector *res;

	if (!(res = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	res->x = x;
	res->y = y;
	return (res);
}

void		ft_free_grid(char **grid)
{
	int i;

	i = -1;
	while (++i < 26)
		free(grid[i]);
	free(grid);
}
