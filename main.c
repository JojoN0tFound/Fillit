/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquivogn <jquivogn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:19:59 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/15 17:22:24 by jquivogn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*tetriminos;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY) == -1))
		write(1, "usage: ./fillit description_file\n", 33);
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
