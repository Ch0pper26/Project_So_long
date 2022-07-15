/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:50:55 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/16 10:56:55 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

void	ft_find_all(t_vars *v)
{
	int		i;
	size_t	j;

	i = 1;
	j = 1;
	v->nb_coin = 0;
	while (i < ft_len_split_no_null(v->map_split))
	{
		while (j < ft_strlen(v->map_split[0]))
		{
			if (v->map_split[i][j] == 'P')
			{
				v->py = i;
				v->px = j;
				v->nb_move = 0;
			}
			if (v->map_split[i][j] == 'C')
				v->nb_coin++;
			j++;
		}
		j = 1;
		i++;
	}
	v->pause = -1;
}

void	ft_find_enemies(t_vars *v)
{
	int		i;
	size_t	j;

	i = 1;
	j = 1;
	v->nb_enemies = 0;
	while (i < ft_len_split_no_null(v->map_split))
	{
		while (j < ft_strlen(v->map_split[0]))
		{
			if (v->map_split[i][j] == 'M')
				v->nb_enemies++;
			if (v->map_split[i][j] == 'E')
			{
				v->ey = i;
				v->ex = j;
			}
			j++;
		}
		j = 1;
		i++;
	}
}
