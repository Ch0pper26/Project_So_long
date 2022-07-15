/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:24:13 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/15 13:23:35 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

void	ft_open_window(t_vars *v, int nb)
{
	v->mlx = mlx_init();
	if (v->mlx == NULL)
		exit(EXIT_FAILURE);
	v->win = mlx_new_window(v->mlx, v->w_size[0], v->w_size[1], "./so_long");
	v->i = ft_init_img(v, nb);
	ft_put_image(v);
	mlx_hook(v->win, 2, 1L << 0, ft_key, v);
	mlx_hook(v->win, DestroyNotify, 0, ft_close_cross, v);
	mlx_loop_hook(v->mlx, ft_auto_move, v);
	ft_display_move(v);
	ft_display_coin(v);
	ft_display_name(v);
	mlx_loop(v->mlx);
}

int	ft_key(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		ft_final_free(vars);
		exit(EXIT_SUCCESS);
	}
	if (vars->pause != 1)
	{
		if (keycode == XK_a || keycode == XK_Left)
			ft_move_player(vars, -1, 'x');
		if (keycode == XK_d || keycode == XK_Right)
			ft_move_player(vars, 1, 'x');
		if (keycode == XK_w || keycode == XK_Up)
			ft_move_player(vars, -1, 'y');
		if (keycode == XK_s || keycode == XK_Down)
			ft_move_player(vars, 1, 'y');
	}
	if (keycode == XK_p)
	{
		vars->pause *= -1;
		ft_display_pause(vars);
	}
	return (0);
}

int	ft_close_cross(t_vars *vars)
{
	ft_final_free(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win_size(t_vars *v)
{
	v->w_size[0] = ft_strlen(v->map_split[0]) * 42;
	v->w_size[1] = ft_len_split_no_null(v->map_split) * 42;
}
