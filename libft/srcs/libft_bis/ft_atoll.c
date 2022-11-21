/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:30:25 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/03 11:24:38 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

long long	ft_atoll(const char *nptr)
{
	size_t		i;
	long long	nb;
	int			signe;

	i = 0;
	nb = 0;
	signe = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r')
		|| (nptr[i] == ' ' && nptr[i] != '\0'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		nb *= 10;
		nb += (nptr[i] - 48);
		i++;
	}
	nb *= signe;
	return (nb);
}
