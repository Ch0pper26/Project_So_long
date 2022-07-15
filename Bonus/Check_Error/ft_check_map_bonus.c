/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:41:00 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 14:38:35 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

int	ft_check_rectangle(char **map_split)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map_split[0]);
	while (map_split[i] != NULL)
	{
		if (ft_strlen(map_split[i]) != len)
			return (ft_print_error("The given map wasn't a rectangle"));
		i++;
	}
	return (0);
}

int	ft_check_characters(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'E' && map[i] != 'P'
			&& map[i] != '\n' && map[i] != 'M')
			return (ft_print_error("There is other letters than 01CEPM"));
		i++;
	}
	return (0);
}

int	ft_check_len(char **map_split)
{
	if (ft_len_split_no_null(map_split) < 3)
		return (ft_print_error("Map too small\nThere is less than 3 lines"));
	if (ft_strlen(map_split[0]) < 3)
		return (ft_print_error("Map too small\nThere is less than 3 columns"));
	return (0);
}

int	ft_check_wall(char **map_split)
{
	int	i;
	int	j;
	int	len_col;
	int	len_line;

	i = 0;
	j = 0;
	len_col = ft_strlen(map_split[0]);
	len_line = ft_len_split_no_null(map_split);
	while (j < len_line)
	{
		while (i < len_col)
		{
			if (j == 0)
				if (map_split[j][i] != '1' || map_split[len_line - 1][i] != '1')
					return (ft_print_error("Map isn't closed by 4 walls of 1"));
			i++;
		}
		if (map_split[j][0] != '1' || map_split[j][len_col - 1] != '1')
			return (ft_print_error("Map isn't closed by 4 walls of 1"));
		j++;
	}
	return (0);
}

int	ft_check_one(char *map)
{
	int	i;
	int	count_c;
	int	count_p;
	int	count_e;

	i = 0;
	count_p = 0;
	count_e = 0;
	count_c = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			count_p++;
		if (map[i] == 'E')
			count_e++;
		if (map[i] == 'C')
			count_c++;
		i++;
	}
	if (count_p != 1 || count_e != 1 || count_c == 0)
		return (ft_print_error("There is an invalid number of P E C"));
	return (0);
}
