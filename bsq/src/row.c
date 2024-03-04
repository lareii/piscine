/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:43:34 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/19 10:11:32 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	is_line_valid(char *l, int n)
{
	while (n > 0)
	{
		--n;
		if (*l != g_data.empty && *l != g_data.obstacle && *l != '\0')
			return (0);
		++l;
	}
	return (1);
}

void	print_rows(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_data.row)
	{
		j = 0;
		while (j < g_data.col)
		{
			(void)write(1, &g_data.rows[i][j], 1);
			++j;
		}
		(void)write(1, "\n", 1);
		++i;
	}
}

int	eval_row_count(char *buff, int *offset)
{
	char	*i;

	i = buff;
	while (*i != '\0')
	{
		if ('0' <= *i && *i <= '9')
		{
			if (offset)
				++*offset;
		}
		else
			break ;
		++i;
	}
	return (ft_atoi(buff, i - buff));
}
