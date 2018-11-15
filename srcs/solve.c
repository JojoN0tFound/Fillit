/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:12:37 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 04:18:40 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

static void		ft_print_grid(char **grid, int min)
{
	int i;
	int j;

	i = -1;
	ft_putendl("\nHERE IS THE SOLUTION:");
	ft_putendl("==============================================\n");
	while (++i < min)
	{
		j = -1;
		while (++j < min)
			ft_putchar(grid[j][i] ? grid[j][i] : '.');
		write(1, "\n", 1);
	}
	ft_putendl("\n==============================================");
	ft_putendl("END OF GRID\n");
}

static void		ft_free_grid(char **grid)
{
	int i;

	i = -1;
	while (++i < 26)
		free(grid[i]);
	free(grid);
}

static int	ft_get_start_index(t_list *tetris)
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
	printf("Counted %d pieces!\n", count);
	while (i * i < count * 4)
		i++;
	return (i); //start index should be (number of tetriminos * 2) rounded to the lowest multiple of 4
}

static int	ft_backtrack_solutions(char **grid, t_list *tetris, int min)
{
	int i;
	int j;
	t_tetris *current;

	if (!tetris)
		return (1); //We placed all the pieces! Solving was successful!
	i = -1;
	current = (t_tetris *)(tetris->content);
	while (++i < min)
	{
		j = -1;
		while (++j < min)
		{
			if (ft_is_valid_pos(grid, ft_get_vector(j, i), current, min - 1))
			{
				// ft_print_grid(grid, min);
				if (ft_backtrack_solutions(grid, tetris->next, min))
					return (1);
				ft_delete_piece(grid, current, j, i);
				// ft_print_grid(grid);
			}
		}
	}
	return (0); //the puzzle was impossible to solve with the provided min length
}

static void	ft_loop(char **grid, t_list *tetris)
{
	int min;

	min = ft_get_start_index(tetris);
	printf("Start index determined as : %d\n", min);
	while (min < 26) //26 is the worst of the worst cases of grid with 26 tetriminos
	{
		if (ft_backtrack_solutions(grid, tetris, min))
		{
			//solved! Print result
			printf("Grid solved within a square of %d length!\n", min);
			ft_print_grid(grid, min);
			ft_free_grid(grid);
			return ;
		}
		else
		{
			//reset the grid and try again with a greater length
			ft_reset_grid(grid);
		}
		min++;
	}
}

int			ft_solve(t_list *tetriminos)
{
	int min;
	char **grid;

	min = 104;
	grid = NULL;
	printf("Initializing the solving grid...\n");
	if (ft_initialize_grid(&grid))
	{
		printf("Grid successfully initialized!\n");
		printf("Solving in progress...\n");
		ft_loop(grid, tetriminos);
		return (1);
	}
	else
		return (0);
}