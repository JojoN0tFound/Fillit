/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 02:50:44 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/17 11:02:56 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int			ft_initialize_grid(char ***grid)
{
	int i;

	i = -1;
	if (!(*grid = (char **)ft_memalloc(26 * sizeof(char *))))
		return (0);
	while (++i < 26)
		if (!((*grid)[i] = (char *)ft_memalloc(26 * sizeof(char))))
		{
			while (--i >= 0)
				free((*grid)[i]);
			return (0);
		}
	return (1);
}

int			ft_is_valid_pos(char **grid, t_vector *xy, t_tetris *tr, int max)
{
	int		i;
	int		bx;
	int		by;

	if (!xy)
		return (0);
	i = -1;
	bx = xy->x;
	by = xy->y;
	while (++i < 4)
	{
		if (bx < 0 || by < 0 || bx > max || by > max || grid[bx][by] != 0)
		{
			free(xy);
			return (0);
		}
		bx += i < 3 ? tr->points[i].x : 0;
		by += i < 3 ? tr->points[i].y : 0;
	}
	i = -1;
	grid[xy->x][xy->y] = tr->value;
	while (++i < 3)
		grid[xy->x += tr->points[i].x][xy->y += tr->points[i].y] = tr->value;
	free(xy);
	return (1);
}

void		ft_reset_grid(char **grid)
{
	int i;
	int j;

	i = -1;
	while (++i < 26)
	{
		j = -1;
		while (++j < 26)
			grid[i][j] = 0;
	}
}

void		ft_delete_piece(char **grid, t_tetris *tr, short x, short y)
{
	int i;

	i = -1;
	grid[x][y] = 0;
	while (++i < 3)
		grid[x += tr->points[i].x][y += tr->points[i].y] = 0;
}
