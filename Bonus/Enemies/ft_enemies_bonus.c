/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemies_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:59:26 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/16 11:00:54 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

int	ft_auto_move(t_vars *v)
{
	static int	frame_rate = 0;

	if (frame_rate > 40000 && v->pause != 1)
	{
		if (v->nb_move > 0)
			ft_move_enemies(v);
		else
			ft_blink_player(v);
		frame_rate = 0;
	}
	frame_rate++;
	return (1);
}

void	ft_init_enemies(t_vars *v)
{
	ft_find_enemies(v);
	if (v->nb_enemies != 0)
	{
		v->en = malloc(sizeof(t_e) * v->nb_enemies);
		ft_enemie_position(v);
	}
}

void	ft_enemie_position(t_vars *v)
{
	int			i;
	size_t		j;
	static int	e = 0;

	i = 1;
	j = 1;
	while (i < ft_len_split_no_null(v->map_split))
	{
		while (j < ft_strlen(v->map_split[0]))
		{
			if (v->map_split[i][j] == 'M')
			{
				v->en[e].e_y = i;
				v->en[e].e_x = j;
				e++;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

void	ft_dead(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->nb_enemies)
	{
		if (v->px == v->en[i].e_x && v->py == v->en[i].e_y)
		{
			ft_final_free(v);
			ft_printf("You're dead\n Game Over \n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
