/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:44:09 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/22 22:37:00 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

// int	check_square(int i, int j)
// {
// 	int	n;
// 	int	k;
// 	int	r;
// 	int	l;
// 	int	p;

// 	n = 1;
// 	k = j + 1;
// 	while (k < g_data.col && i + n < g_data.row)
// 	{
// 		if (g_data.rows[i][k] != g_data.empty)
// 			return (n);
// 		r = i + n;
// 		l = i + 1;
// while (l < r)
// {
// 	if (g_data.rows[l][k] != g_data.empty)
// 		return (n);
// 	++l;
// }
// 		p = j;
// 		while (p <= k)
// 		{
// 			if (g_data.rows[r][p] != g_data.empty)
// 				return (n);
// 			++p;
// 		}
// 		++k;
// 		++n;
// 	}
// 	return (n);
// }

int	check2(int l, int r, int k)
{
	while (l < r)
	{
		if (g_data.rows[l][k] != g_data.empty)
			return (0);
		++l;
	}
	return (1);
}

int	check(int p, int k, int r)
{
	while (p <= k)
	{
		if (g_data.rows[r][p] != g_data.empty)
			return (0);
		++p;
	}
	return (1);
}

int	check_square(int i, int j)
{
	int	n;
	int	k;
	int	r;
	int	l;
	int	p;

	n = 1;
	k = j + 1;
	while (k < g_data.col && i + n < g_data.row)
	{
		if (g_data.rows[i][k] != g_data.empty)
			return (n);
		r = i + n;
		l = i + 1;
		if (!check(l, r, k))
			return (n);
		p = j;
		if (!check2(p, k, r))
			return (n);
		++k;
		++n;
	}
	return (n);
}

void	find_biggest_square(void)
{
	int		i;
	int		j;
	char	*row;

	i = 0;
	while (i < g_data.row)
	{
		row = g_data.rows[i];
		j = 0;
		while (j < g_data.col)
		{
			if (row[j] == g_data.empty && check_square(i, j) > g_data.b_n)
			{
				g_data.b_row = i;
				g_data.b_col = j;
				g_data.b_n = check_square(i, j);
			}
			++j;
		}
		++i;
	}
}

void	fill_square(void)
{
	int		row_end;
	int		col_end;
	int		i;
	int		j;
	char	*row;

	i = g_data.b_row;
	row_end = g_data.b_row + g_data.b_n;
	col_end = g_data.b_col + g_data.b_n;
	i = g_data.b_row;
	while (i < row_end)
	{
		j = g_data.b_col;
		row = g_data.rows[i];
		while (j < col_end)
		{
			row[j] = g_data.full;
			++j;
		}
		++i;
	}
}
