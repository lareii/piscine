/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:27:40 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/02/12 09:19:40 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tmp;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	tmp = malloc(size * sizeof(int));
	if (!tmp)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (i < size)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (size);
}
