/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:44:31 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 12:17:14 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

size_t	ft_len_files(int fd)
{
	int				end;
	char			tmp_dict[1];
	unsigned int	len;

	len = 0;
	end = 1;
	while (end == 1)
	{
		end = read(fd, tmp_dict, 1);
		if (end < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (end > 0)
			len++;
	}
	return (len);
}

char	*ft_recup_map(char	*name_file)
{
	int		fd;
	char	*map;
	size_t	len;

	fd = open(name_file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	len = ft_len_files(fd);
	close(fd);
	if (len <= 1)
	{
		ft_print_error("Empty Files");
		exit (EXIT_FAILURE);
	}
	map = malloc(sizeof(char) * len);
	if (!map)
		exit(EXIT_FAILURE);
	fd = open(name_file, O_RDONLY);
	read(fd, map, len);
	map[len - 1] = '\0';
	close(fd);
	return (map);
}
