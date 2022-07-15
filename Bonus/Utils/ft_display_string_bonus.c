/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:03:55 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/15 13:25:18 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

void	ft_display_move(t_vars *v)
{
	char	*number;

	number = ft_itoa((v->nb_move - 1));
	number = ft_strjoin_free(number, " moves");
	mlx_string_put(v->mlx, v->win, 28, 28, 0000, number);
	free(number);
	number = ft_itoa(v->nb_move);
	number = ft_strjoin_free(number, " moves");
	mlx_string_put(v->mlx, v->win, 28, 28, 4294967295, number);
	free(number);
}

void	ft_display_coin(t_vars *v)
{
	char	*number;

	number = ft_itoa(v->nb_coin + 1);
	number = ft_strjoin_free(number, " remaining collectibles");
	mlx_string_put(v->mlx, v->win, 28, 14, 0000, number);
	free(number);
	number = ft_itoa(v->nb_coin);
	number = ft_strjoin_free(number, " remaining collectibles");
	mlx_string_put(v->mlx, v->win, 28, 14, 4294967295, number);
	free(number);
}

void	ft_display_name(t_vars *v)
{
	int	len;
	int	w;

	w = 4294967295;
	len = ((ft_strlen(v->map_split[0]) / 2) - 1) * 42;
	if (ft_strlen(v->map_split[0]) > 11)
	{
		mlx_string_put(v->mlx, v->win, len, 14, w, "=====================");
		mlx_string_put(v->mlx, v->win, len, 28, w, " Black    &    White ");
		mlx_string_put(v->mlx, v->win, len, 42, w, "=====================");
	}
}

void	ft_display_pause(t_vars *v)
{
	char	*n;

	if (v->pause == 1)
	{
		n = ft_strjoin_free(ft_itoa(v->nb_coin), " remaining collectibles");
		mlx_string_put(v->mlx, v->win, 28, 14, 0000, n);
		free(n);
		n = ft_strjoin_free(ft_itoa((v->nb_move)), " moves");
		mlx_string_put(v->mlx, v->win, 28, 28, 0000, n);
		free(n);
		mlx_string_put(v->mlx, v->win, 28, 28, 4294967295, "PAUSE");
	}
	if (v->pause == -1)
	{
		mlx_string_put(v->mlx, v->win, 28, 28, 0000, "PAUSE");
		n = ft_strjoin_free(ft_itoa(v->nb_coin), " remaining collectibles");
		mlx_string_put(v->mlx, v->win, 28, 14, 4294967295, n);
		free(n);
		n = ft_strjoin_free(ft_itoa((v->nb_move)), " moves");
		mlx_string_put(v->mlx, v->win, 28, 28, 4294967295, n);
		free(n);
	}
}
