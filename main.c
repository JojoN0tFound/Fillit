/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:19:59 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/17 11:07:57 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

static void	ft_no_file(char *file_name)
{
	write(1, "./fillit: ", 10);
	write(1, file_name, ft_strlen(file_name));
	write(1, ": No such file or directory\n", 28);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*tetriminos;

	tetriminos = NULL;
	if (argc != 2)
		write(1, "usage: ./fillit description_file\n", 33);
	else if ((fd = open(argv[1], O_RDONLY) == -1))
		ft_no_file(argv[1]);
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			write(1, "error\n", 6);
		else
		{
			if ((tetriminos = ft_get_tetriminos(fd)))
			{
				if (!ft_solve(tetriminos))
					write(1, "error\n", 6);
				ft_lstdel(&tetriminos, &ft_bzero);
			}
			else
				write(1, "error\n", 6);
		}
	}
	return (0);
}
