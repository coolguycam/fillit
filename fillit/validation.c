/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 09:01:28 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/24 15:25:20 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_char(char **tetra)
{
	int i;
	int j;
	int hash;

	i = 0;
	j = 0;
	hash = 0;
	while (i < 4)
	{
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j] != '.' && tetra[i][j] != '#')
				return (0);
			else if (tetra[i][j] == '#')
				hash++;
			j++;
		}
		j = 0;
		i++;
	}
	if (hash != 4)
		return (0);
	return (1);
}

int		check_hash(char **tetra)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < 4)
	{
		while (tetra[i][j] != '\0')
		{
			if (tetra[i][j++] == '#')
			{
				(i < 3 && tetra[i + 1][j] == '#') && (count++);
				(i > 0 && tetra[i - 1][j] == '#') && (count++);
				(j < 3 && tetra[i][j + 1] == '#') && (count++);
				(j > 0 && tetra[i][j - 1] == '#') && (count++);
			}
		}
		j = 0;
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
