/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:33:00 by eblondee          #+#    #+#             */
/*   Updated: 2022/06/07 10:45:50 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
	{
		ft_print_error("Invalid number of argument were given");
		return (0);
	}
	ft_check(argv[1]);
	vars = malloc(sizeof(t_vars) * 1);
	vars->map = ft_recup_map(argv[1]);
	vars->map_split = ft_split(vars->map, '\n');
	ft_find_all(vars);
	ft_win_size(vars);
	ft_open_window(vars);
}
