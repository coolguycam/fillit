/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:35:44 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/25 16:11:31 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putstr("error");
	exit(0);
}

char	**get_next_tetra(const int fd)
{
	char	**grid;
	char	*line;
	int		i;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * 5);
	while (i < 5)
	{
		if (get_next_line(fd, &line) == 1)
			grid[i++] = ft_strdup(line);
		else
			error();
	}
	if (grid[4][0] != '\0')
		error();
	if (!check_char(grid))
		error();
	if (!check_hash(grid))
		error();
	return (grid);
}

int		size_of_file(char *arg)
{
	int		fd;
	int		count;
	char	buf[BUFF_SIZE + 1];

	fd = open(arg, O_RDONLY);
	count = read(fd, buf, BUFF_SIZE);
	close(fd);
	return (count);
}

int		find_num_tetra(char *str)
{
	int num;
	int	size;

	size = size_of_file(str);
	if (size == 0)
		return (1);
	if (size % 21 == 0)
		num = size / 21;
	else
		num = (size / 21) + 1;
	return (num);
}

int		main(int ac, char **av)
{
	int		num;
	t_tetra list[26];
	char	a;
	int		fd;

	if (ac == 2)
	{
		ac = 0;
		a = 'A';
		num = find_num_tetra(av[1]);
		fd = open(av[1], O_RDONLY);
		while (ac < num)
		{
			av = get_next_tetra(fd);
			list[ac] = get_coords(av);
			list[ac] = reset_coords(list[ac]);
			list[ac++].name = a;
			a++;
			free(av);
		}
		close(fd);
		finish(list, num);
	}
	else
		ft_putstr("usage: fillit input_file\n");
}
