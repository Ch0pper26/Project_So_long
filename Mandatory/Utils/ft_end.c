/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:21:28 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 12:32:12 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

void	ft_end(t_vars *v)
{
	if (v->nb_coin == 0 && v->map_split[v->py][v->px] == 'E')
	{
		ft_printf("Congratulations you finished the game\n");
		ft_printf("You beat it in %d moves\n", v->nb_move);
		ft_final_free(v);
		exit(EXIT_SUCCESS);
	}
}
