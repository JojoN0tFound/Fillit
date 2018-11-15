/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:37:35 by mmousson          #+#    #+#             */
/*   Updated: 2018/11/14 19:43:34 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

t_vector	*ft_get_vector(int x, int y)
{
	t_vector *res;

	if (!(res = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	res->x = x;
	res->y = y;
	return (res);
}