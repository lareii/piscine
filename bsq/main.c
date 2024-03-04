/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:09:52 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/18 23:36:56 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

struct s_data	g_data;

void	from_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		fread_map(argv[i]);
		++i;
	}
}

void	from_stdin(void)
{
	int		n;
	char	**end;
	char	*buff;
	int		size;
	char	**i;

	n = read(0, g_data.buffer, g_data.buffsize);
	setup_info(g_data.buffer);
	g_data.rows = malloc(sizeof(char *) * g_data.row);
	end = g_data.rows + g_data.row;
	buff = g_data.buffer;
	size = g_data.buffsize;
	i = g_data.rows;
	while (i < end)
	{
		n += read(0, buff, size - n);
		if (n >= size)
		{
			buff = resize_buffer();
			size = g_data.buffsize / 2;
			n = 0;
		}
		++i;
	}
	read_map();
}

int	main(int argc, char *argv[])
{
	setup_data();
	g_data.buffer = malloc(sizeof(char) * g_data.buffsize);
	if (argc != 1)
		from_args(argc, argv);
	else
		from_stdin();
	free(g_data.buffer);
	g_data.buffer = NULL;
	return (0);
}
