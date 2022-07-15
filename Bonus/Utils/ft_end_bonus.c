/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:21:28 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 13:28:04 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

void	ft_end(t_vars *v)
{
	int	ex_i;
	int	ey_i;

	ex_i = (v->ex) * 42;
	ey_i = (v->ey) * 42;
	if (v->nb_coin == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[5], ex_i, ey_i);
	if (v->nb_coin == 0 && v->map_split[v->py][v->px] == 'E')
	{
		ft_printf("Congratulations you finished the game\n");
		ft_printf("You beat it in %d moves\n", v->nb_move);
		ft_final_free(v);
		exit(EXIT_SUCCESS);
	}
}
