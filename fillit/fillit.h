/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdimitro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:46:57 by cdimitro          #+#    #+#             */
/*   Updated: 2019/04/25 16:10:27 by cdimitro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct	s_tetra
{
	char		name;
	int			x[4];
	int			y[4];
}				t_tetra;

void			error(void);
int				size_of_file(char *arg);
void			print_map(char **map);
char			**get_next_tetra(const int fd);
int				check_char(char **tetra);
int				check_hash(char **tetra);
t_tetra			get_coords(char **grid);
t_tetra			reset_coords(t_tetra tetra);
char			**initial_map(int num);
char			**make_map(int num);
char			**place_tetra(t_tetra tetra, char **map, int y, int x);
char			**remove_tetra(char **map, char name, int size);
int				placement_check(t_tetra tetra, char **map, int y, int x);
int				can_place(t_tetra tetra, char **map, int y, int x);
char			**resize_map(char **map);
int				backtrack(t_tetra list[26], char **map, int i, int size);
char			**fillit(char **map, t_tetra list[26], int size);
void			finish(t_tetra list[26], int num);

#endif
