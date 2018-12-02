/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:12:37 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/17 10:37:50 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static void		ft_print_grid(char **grid, int min)
{
	int i;
	int j;

	i = -1;
	while (++i < min)
	{
		j = -1;
		while (++j < min)
			ft_putchar(grid[j][i] ? grid[j][i] : '.');
		write(1, "\n", 1);
	}
}

static int		ft_get_start_index(t_list *tetris)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (tetris)
	{
		tetris = tetris->next;
		count++;
	}
	while (i * i < count * 4)
		i++;
	return (i);
}

static int		ft_backtrack_solutions(char **grid, t_list *tetris, int min)
{
	int			i;
	int			j;
	t_tetris	*current;

	if (!tetris)
		return (1);
	i = -1;
	current = (t_tetris *)(tetris->content);
	while (++i < min)
	{
		j = -1;
		while (++j < min)
		{
			if (ft_is_valid_pos(grid, ft_get_vector(j, i), current, min - 1))
			{
				if (ft_backtrack_solutions(grid, tetris->next, min))
					return (1);
				ft_delete_piece(grid, current, j, i);
			}
		}
	}
	return (0);
}

static void		ft_loop(char **grid, t_list *tetris)
{
	int min;

	min = ft_get_start_index(tetris);
	while (min < 26)
	{
		if (ft_backtrack_solutions(grid, tetris, min))
		{
			ft_print_grid(grid, min);
			ft_free_grid(grid);
			return ;
		}
		else
			ft_reset_grid(grid);
		min++;
	}
}

int				ft_solve(t_list *tetriminos)
{
	char	**grid;

	grid = NULL;
	if (ft_initialize_grid(&grid))
	{
		ft_loop(grid, tetriminos);
		return (1);
	}
	else
		return (0);
}
