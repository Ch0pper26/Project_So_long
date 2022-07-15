/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:21:01 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 11:17:45 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

void	ft_check(char *file)
{
	int		error;
	char	*map;
	char	**map_split;

	ft_check_extension(file);
	map = ft_recup_map(file);
	map_split = ft_split(map, '\n');
	error = 0;
	if (map_split[0] == NULL)
		error += ft_print_error("Split Failed : There is only \\n in the file");
	if (error == 0 && ft_check_rectangle(map_split) == 1)
		error++;
	if (error == 0 && ft_check_len(map_split) == 1)
		error++;
	if (error == 0 && ft_check_characters(map) == 1)
		error++;
	if (error == 0 && ft_check_wall(map_split) == 1)
		error++;
	if (error == 0 && ft_check_one(map) == 1)
		error++;
	free(map);
	ft_free_split(map_split);
	if (error != 0)
		exit(EXIT_FAILURE);
}

void	ft_check_extension(char *file)
{
	if (strcmp((file + ft_strlen(file)) - 4, ".ber") != 0)
	{
		ft_print_error("File name wasn't good, it must be [file_name.ber]");
		exit(EXIT_FAILURE);
	}
}
