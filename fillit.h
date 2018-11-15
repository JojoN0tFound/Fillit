/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:20:43 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 17:30:38 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

typedef struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef struct	s_tetris
{
	char		value;
	t_vector	points[3];
	char		lst_min_neighbours;
}				t_tetris;

t_list			*ft_get_tetriminos(int fd);
t_vector		*ft_get_vector(int x, int y);
int				ft_solve(t_list *tetriminos);
int				ft_initialize_grid(char ***grid);
int				ft_is_valid_pos(char **grid, t_vector *xy, t_tetris *piece,
					int max);
void			ft_find_square_size(char **grid, int *min);
void			ft_delete_piece(char **grid, t_tetris *piece, short x, short y);
void			ft_reset_grid(char **grid);
void			ft_free_grid(char **grid);

#endif
