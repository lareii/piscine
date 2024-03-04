/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:43:31 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/19 15:22:54 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

char	*resize_buffer(void)
{
	char	*end;
	char	*new;
	char	*p;
	char	*k;

	end = g_data.buffer + g_data.buffsize;
	g_data.buffsize *= 2;
	new = malloc(sizeof(char *) * g_data.buffsize);
	p = g_data.buffer;
	k = new;
	while (p < end)
		*k++ = *p++;
	free(g_data.buffer);
	g_data.buffer = new;
	return (k);
}

char	*next(char *buff, int *count)
{
	char	*end;
	char	*i;

	end = g_data.buffer + g_data.buffsize;
	i = buff;
	while (i < end - 1)
	{
		if (*i == '\n')
			return (i + 1);
		else if (count)
			++*count;
		++i;
	}
	return (NULL);
}

void	read_map(void)
{
	if (setup())
	{
		find_biggest_square();
		fill_square();
		print_rows();
	}
	g_data.row = 0;
	g_data.col = 0;
	g_data.b_row = 0;
	g_data.b_n = 0;
	g_data.b_col = 0;
	g_data.empty = '\0';
	g_data.full = '\0';
	g_data.obstacle = '\0';
	free(g_data.rows);
	g_data.rows = NULL;
}

int	is_file_valid(int fd)
{
	if (fd == -1)
	{
		(void)write(2, "file could not opened\n", 23);
		return (0);
	}
	return (1);
}

void	fread_map(const char *path)
{
	int		f;
	char	*buff;
	int		size;
	int		n;

	f = open(path, 0660);
	if (!is_file_valid(f))
		return ;
	buff = g_data.buffer;
	size = g_data.buffsize;
	while (1)
	{
		n = read(f, buff, size);
		if (n == size)
		{
			buff = resize_buffer();
			size = g_data.buffsize / 2;
			continue ;
		}
		break ;
	}
	read_map();
	(void)close(f);
}
