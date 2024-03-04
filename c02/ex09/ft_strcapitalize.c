/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:31:11 by ebabaogl          #+#    #+#             */
/*   Updated: 2024/01/29 12:44:17 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = 'z' - ('Z' - str[i]);
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	is_first_char;
	int	i;

	i = 0;
	is_first_char = 1;
	str = ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_first_char == 1)
			{
				str[i] = 'Z' - ('z' - str[i]);
				is_first_char = 0;
			}
		}
		else if (str[i] >= '0' && str[i] <= '9')
			is_first_char = 0;
		else
			is_first_char = 1;
		i++;
	}
	return (str);
}
