/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:00:20 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/07 16:11:03 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_find_min(int *tab, int len)
{
	int	i;
	int	min;

	i = 0;
	min = tab[0];
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	ft_find_max(int *tab, int len)
{
	int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	ft_find_med(int *tab, int len)
{
	int	i;
	int	med;

	i = 0;
	med = ft_find_min(tab, len);
	while (i < (len / 2))
	{
		med = ft_next_int(tab, len, med);
		i++;
	}
	return (med);
}

int	ft_next_int(int *tab, int len, int current_int)
{
	int	next_int;
	int	i;

	i = 0;
	next_int = ft_find_max(tab, len);
	if (current_int == next_int)
		return (current_int);
	while (i < len)
	{
		if (tab[i] < next_int && tab[i] > current_int)
			next_int = tab[i];
		i++;
	}
	return (next_int);
}

int	ft_prev_int(int *tab, int len, int current_int)
{
	int	prev_int;
	int	i;

	i = 0;
	prev_int = ft_find_min(tab, len);
	if (current_int == prev_int)
		return (current_int);
	while (i < len)
	{
		if (tab[i] > prev_int && tab[i] < current_int)
			prev_int = tab[i];
		i++;
	}
	return (prev_int);
}
