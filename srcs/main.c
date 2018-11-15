/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:19:59 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/14 23:16:11 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

void			ft_display_tetriminos_list(t_list *list)
{
	int			i;
	t_tetris	*current;

	i = 1;
	while (list)
	{
		printf("Tetrimino number %d :\n", i++);
		printf("=== Displaying infos... ===\n\n");
		current = (t_tetris *)list->content;
		printf("Letter = %c\n", current->value);
		for (int i = 0; i < 3; i++)
		{
				printf("Vector[%d].x = %d\n", i, current->points[i].x);
				printf("Vector[%d].y = %d\n", i, current->points[i].y);
		}
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	int fd;
	t_list	*tetriminos;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY) == -1))
		write(1, "usage: ./fillit description_file\n", 33);
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			write (1, "error\n", 6);
		else
		{
			if ((tetriminos = ft_get_tetriminos(fd)))
			{
				//solve();
				ft_display_tetriminos_list(tetriminos);
				printf("\nTETRIMINOS SUCCESSULLY READ! SOLVING...\n");
				if (ft_solve(tetriminos))
				{
					//display result
				}
				else
					write(1, "error\n", 6);
				ft_lstdel(&tetriminos, &ft_bzero);
			}
			else
			{
				//quit
				write(1, "error\n", 6);
			}
		}
	}
	return (0);
}
