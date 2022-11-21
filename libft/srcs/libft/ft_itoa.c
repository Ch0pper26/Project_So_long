/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:09:32 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/04 11:21:41 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

static int	ft_intlen(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*number;
	long	nb;
	int		size;
	int		i;

	size = ft_intlen(n);
	nb = n;
	i = 1;
	number = malloc(sizeof(char) * (size + 1));
	if (number == NULL)
		return (NULL);
	if (nb < 0)
	{
		number[0] = '-';
		nb *= -1;
	}
	number[size] = '\0';
	while (nb > 9)
	{
		number[size - i] = ((nb % 10) + 48);
		nb = nb / 10;
		i++;
	}
	number[size - i] = nb + 48;
	return (number);
}
