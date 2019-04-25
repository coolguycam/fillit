/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:48:38 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/25 16:10:05 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetra	get_coords(char **grid)
{
	t_tetra	tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (grid[i][0] != '\0')
	{
		while (grid[i][j] != '\0')
		{
			if (grid[i][j] == '#')
			{
				tab.x[k] = j;
				tab.y[k] = i;
				k++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

t_tetra	reset_coords(t_tetra tetra)
{
	t_tetra	res;
	int		i;
	int		x_temp;
	int		y_temp;

	i = 1;
	x_temp = tetra.x[0];
	y_temp = tetra.y[0];
	while (i < 4)
	{
		res.x[i] = tetra.x[i] - x_temp;
		res.y[i] = tetra.y[i] - y_temp;
		i++;
	}
	res.x[0] = 0;
	res.y[0] = 0;
	return (res);
}
