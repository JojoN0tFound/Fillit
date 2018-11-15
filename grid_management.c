/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 02:50:44 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 17:11:07 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static int	ft_find_neighbours(char **grid, short x, short y, char except)
{
	if (x - 1 > 0)
		if ((grid[x - 1][y] != except && ft_isalpha(grid[x - 1][y])))
			return (1);
	if (x + 1 < 104)
		if ((grid[x + 1][y] != except && ft_isalpha(grid[x + 1][y])))
			return (1);
	if (y - 1 > 0)
		if ((grid[x][y - 1] != except && ft_isalpha(grid[x][y - 1])))
			return (1);
	if (y + 1 < 104)
		if ((grid[x][y + 1] != except && ft_isalpha(grid[x][y + 1])))
			return (1);
	return (0);
}

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
	short	neighbours;

	i = -1;
	bx = xy->x;
	by = xy->y;
	neighbours = 0;
	while (++i < 4)
	{
		if (bx < 0 || by < 0 || bx > max || by > max || grid[bx][by] != 0)
			return (0);
		neighbours += ft_find_neighbours(grid, by, bx, tr->value);
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
