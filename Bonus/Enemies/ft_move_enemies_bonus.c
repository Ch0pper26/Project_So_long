/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemies_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:39:12 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/09 14:15:36 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

void	ft_move_enemies(t_vars *v)
{
	int		*pos;
	int		random;
	time_t	t;
	int		i;

	i = 0;
	srand((unsigned) time(&t));
	while (i < v->nb_enemies)
	{
		pos = ft_possible_move(v->en[i].e_y, v->en[i].e_x, v);
		random = rand() % 4;
		ft_change_coord(random, v, i, pos);
		free(pos);
		ft_dead(v);
		i++;
	}
}

int	*ft_possible_move(int y, int x, t_vars *v)
{
	int	*pos;

	pos = ft_calloc(sizeof(int), 4);
	if (v->map_split[y - 1][x] == '0')
		pos[0] = 1;
	if (v->map_split[y][x + 1] == '0')
		pos[1] = 1;
	if (v->map_split[y + 1][x] == '0')
		pos[2] = 1;
	if (v->map_split[y][x - 1] == '0')
		pos[3] = 1;
	return (pos);
}

void	ft_change_coord(int random, t_vars *v, int i, int *pos)
{
	v->map_split[v->en[i].e_y][v->en[i].e_x] = '0';
	if (random == 0 && pos[random] == 1)
	{
		v->en[i].e_y--;
		ft_move_imgenemy(v, -1, 'y', i);
	}
	if (random == 1 && pos[random] == 1)
	{
		v->en[i].e_x++;
		ft_move_imgenemy(v, 1, 'x', i);
	}
	if (random == 2 && pos[random] == 1)
	{
		v->en[i].e_y++;
		ft_move_imgenemy(v, 1, 'y', i);
	}
	if (random == 3 && pos[random] == 1)
	{
		v->en[i].e_x--;
		ft_move_imgenemy(v, -1, 'x', i);
	}
	v->map_split[v->en[i].e_y][v->en[i].e_x] = 'M';
}

void	ft_move_imgenemy(t_vars *v, int i, char c, int e)
{
	int	p_y;
	int	p_x;

	if (c == 'y')
	{
		p_x = v->en[e].e_x * 42;
		p_y = (v->en[e].e_y + (i * -1)) * 42;
		if (v->map_split[(v->en[e].e_y + (i * -1))][v->en[e].e_x] != 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[0], p_x, p_y);
		else
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[2], p_x, p_y);
		p_y = v->en[e].e_y * 42;
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[4], p_x, p_y);
	}
	else if (c == 'x')
	{
		p_y = v->en[e].e_y * 42;
		p_x = (v->en[e].e_x + (i * -1)) * 42;
		if (v->map_split[v->en[e].e_y][v->en[e].e_x + (i * -1)] != 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[0], p_x, p_y);
		else
			mlx_put_image_to_window(v->mlx, v->win, v->i->img[2], p_x, p_y);
		p_x = v->en[e].e_x * 42;
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[4], p_x, p_y);
	}
}
