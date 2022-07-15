/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:38:56 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/09 13:47:02 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

void	ft_move_player(t_vars *v, int i, char c)
{
	if (c == 'y')
	{
		if (v->map_split[v->py + i][v->px] != '1')
		{
			v->py += i;
			v->nb_move++;
			ft_printf("%d\n", v->nb_move);
			if (v->map_split[v->py][v->px] == 'C')
				ft_coin(v);
			ft_move_imgplayer(v, i, c);
		}
	}
	else if (c == 'x')
	{
		if (v->map_split[v->py][v->px + i] != '1')
		{
			v->px += i;
			v->nb_move++;
			ft_printf("%d\n", v->nb_move);
			if (v->map_split[v->py][v->px] == 'C')
				ft_coin(v);
			ft_move_imgplayer(v, i, c);
		}
	}
	ft_end(v);
}

void	ft_move_imgplayer(t_vars *v, int i, char c)
{
	int	p_y;
	int	p_x;

	if (c == 'y')
	{
		p_x = v->px * 42;
		p_y = (v->py + (i * -1)) * 42;
		if (v->map_split[(v->py + (i * -1))][v->px] != 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[0], p_x, p_y);
		else
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[2], p_x, p_y);
		p_y = v->py * 42;
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[1], p_x, p_y);
	}
	else if (c == 'x')
	{
		p_y = v->py * 42;
		p_x = (v->px + (i * -1)) * 42;
		if (v->map_split[v->py][(v->px + (i * -1))] != 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[0], p_x, p_y);
		else
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[2], p_x, p_y);
		p_x = v->px * 42;
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[1], p_x, p_y);
	}
}

void	ft_coin(t_vars *v)
{
	v->nb_coin--;
	v->map_split[v->py][v->px] = '0';
}
