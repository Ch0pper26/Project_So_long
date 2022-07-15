/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:08:55 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 10:45:37 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

void	ft_final_free(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_destroy_img(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_split(vars->map_split);
	free(vars->map);
	free(vars);
}

void	ft_destroy_img(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->i->len)
	{
		mlx_destroy_image(v->mlx, v->i->img[i]);
		i++;
	}
	free(v->i);
}
