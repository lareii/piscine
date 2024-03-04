/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:51:58 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/19 10:23:34 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

struct	s_data
{
	char	*buffer;
	char	**rows;
	int		buffsize;
	char	full;
	char	obstacle;
	char	empty;
	int		row;
	int		col;
	int		b_row;
	int		b_col;
	int		b_n;
};

extern struct s_data	g_data;

int		ft_atoi(char *s, int n);
char	*resize_buffer(void);
char	*next(char *buff, int *count);
void	read_map(void);
void	fread_map(const char *path);
int		is_line_valid(char *l, int n);
void	print_rows(void);
int		eval_row_count(char *buff, int *offset);
int		setup_info(char *buffer);
int		setup(void);
void	setup_data(void);
int		check_square(int i, int j);
void	find_biggest_square(void);
void	fill_square(void);

#endif
