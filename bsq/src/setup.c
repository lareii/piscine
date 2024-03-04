/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:43:36 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/19 10:13:30 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	setup_info(char *buffer)
{
	int	offset;
	int	rowchars;

	offset = 5;
	rowchars = 0;
	g_data.row = eval_row_count(buffer, &rowchars);
	g_data.col = next(next(buffer, NULL), NULL) - buffer - offset - rowchars;
	g_data.empty = buffer[rowchars];
	g_data.obstacle = buffer[rowchars + 1];
	g_data.full = buffer[rowchars + 2];
	if (g_data.empty == g_data.obstacle || g_data.empty == g_data.full
		|| g_data.obstacle == g_data.empty || g_data.obstacle == g_data.full
		|| g_data.full == g_data.obstacle || g_data.full == g_data.empty)
	{
		(void)write(1, "map error\n", 11);
		return (0);
	}
	return (1);
}

int	setup(void)
{
	char	**end;
	char	*line;
	char	**i;
	int		n;

	if (!setup_info(g_data.buffer))
		return (0);
	g_data.rows = malloc(sizeof(char *) * g_data.row);
	end = g_data.rows + g_data.row;
	line = next(g_data.buffer, NULL);
	i = g_data.rows;
	while (i < end)
	{
		*i = line;
		n = 0;
		line = next(line, &n);
		if (n != g_data.col || !is_line_valid(line, n))
		{
			(void)write(1, "map error\n", 11);
			return (0);
		}
		++i;
	}
	return (1);
}

void	setup_data(void)
{
	g_data.buffsize = 1024;
	g_data.row = 0;
	g_data.col = 0;
	g_data.full = '\0';
	g_data.obstacle = '\0';
	g_data.empty = '\0';
	g_data.b_row = -1;
	g_data.b_col = -1;
	g_data.b_n = -1;
}
