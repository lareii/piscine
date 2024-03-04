/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emrozmen <emrozmen@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:48:23 by emrozmen          #+#    #+#             */
/*   Updated: 2024/01/27 13:48:26 by emrozmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, char edge, char mid)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if (col == 1 || col == x)
			ft_putchar(edge);
		else
			ft_putchar(mid);
		col++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	row = 1;
	while (row <= y && x >= 1 && y >= 1)
	{
		if (row == 1 || row == y)
			ft_print(x, 'o', '-');
		else
			ft_print(x, '|', ' ');
		row++;
	}
}
