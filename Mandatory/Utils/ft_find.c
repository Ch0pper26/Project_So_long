/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:50:55 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/06 18:25:47 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

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
}
