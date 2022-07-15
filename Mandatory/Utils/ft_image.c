/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:54:01 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/06 15:17:54 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long.h"

t_i	*ft_init_img(t_vars *v)
{
	int		w;
	int		h;
	t_i		*tab;

	tab = malloc(sizeof(t_img));
	tab->len = 4;
	tab->img[0] = mlx_xpm_file_to_image(v->mlx, "./img/floor.xpm", &w, &h);
	tab->img[1] = mlx_xpm_file_to_image(v->mlx, "./img/Mr_Bw.xpm", &w, &h);
	tab->img[2] = mlx_xpm_file_to_image(v->mlx, "./img/ex_0.xpm", &w, &h);
	tab->img[3] = mlx_xpm_file_to_image(v->mlx, "./img/c.xpm", &w, &h);
	return (tab);
}

void	ft_put_image(t_vars *v)
{
	int	lines;
	int	colums;
	int	i;
	int	j;

	lines = ft_len_split_no_null(v->map_split);
	colums = ft_strlen(v->map_split[0]);
	i = 1;
	j = 1;
	while (i < lines)
	{
		while (j < colums)
		{
			ft_good_put(i, j, v->map_split[i][j], v);
			j++;
		}
		j = 1;
		i++;
	}
}

void	ft_good_put(int i, int j, char c, t_vars *v)
{
	if (c == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[0], j * 42, i * 42);
	else if (c == 'P')
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[1], j * 42, i * 42);
	else if (c == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[2], j * 42, i * 42);
	else if (c == 'C')
		mlx_put_image_to_window(v->mlx, v->win, v->i->img[3], j * 42, i * 42);
}
