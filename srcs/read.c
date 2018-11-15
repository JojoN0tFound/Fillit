/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 06:34:34 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 04:04:13 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

static void		ft_put_vector(t_tetris *new, int x, int y, int piece)
{
	new->points[piece].x = x;
	new->points[piece].y = y;
}

static t_tetris	*ft_new_piece(char *str)
{
	int			i;
	int			piece;
	t_tetris	*new;

	i = -1;
	piece = 0;
	if (!(new = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '#' && piece < 3)
		{
			if (str[i + 1] == '#')
				ft_put_vector(new, 1, 0, piece++);
			else if (str[i + 3] == '#')
				ft_put_vector(new, -2, 1, piece++);
			else if (str[i + 4] == '#')
				ft_put_vector(new, -1, 1, piece++);
			else if (i < 14 && str[i + 5] == '#')
				ft_put_vector(new, 0, 1, piece++);
		}
	}
	return (new);
}

static t_tetris	*ft_check_tetriminos(char *str)
{
	int			i;
	int			c;
	int			cnt;

	c = 0;
	i = -1;
	cnt = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			cnt += (str[i + 1] == '#');
			cnt += (i <= 13 && str[i + 5] == '#');
			cnt += (i > 0 && str[i - 1] == '#');
			cnt += (i >= 5 && str[i - 5] == '#');
			c++;
		}
		else if ((i % 5 == 4 && str[i] != '\n')
					|| (i % 5 != 4 && str[i] != '.'))
			return (NULL);
	}
	return (((cnt == 6 || cnt == 8) && c == 4) ? ft_new_piece(str) : NULL);
}

t_list			*ft_get_tetriminos(int fd)
{
	char		letter;
	char		buf[21];
	t_list		*list;
	t_tetris	*new;

	letter = 'A';
	while (read(fd, buf, 21) >= 20)
	{
		buf[20] = '\0';
		if ((new = ft_check_tetriminos(buf)))
		{
			new->value = letter++;
			ft_lstpush(&list, ft_lstnew(new, sizeof(t_tetris)));
			free(new);
		}
		else
		{
			ft_lstdel(&list, &ft_bzero);
			return (NULL);
		}
	}
	return (list);
}
