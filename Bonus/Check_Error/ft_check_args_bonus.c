/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:27:52 by eblondee          #+#    #+#             */
/*   Updated: 2022/07/05 11:09:38 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_so_long_bonus.h"

int	ft_check_is_int(char *nb)
{
	if (ft_check_number(nb))
	{
		exit(EXIT_FAILURE);
		return (1);
	}
	if (ft_check_int(nb))
	{
		exit(EXIT_FAILURE);
		return (1);
	}
	return (0);
}

int	ft_check_number(char *stack)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (stack[i])
	{
		if (stack[i] == '-')
		{
			if ((ft_isdigit(stack[i + 1]) == 0))
				return (ft_print_error("The second argument is not a number"));
			count++;
		}
		if ((ft_isdigit(stack[i]) == 0 && stack[i] != '-') || count > 1)
			return (ft_print_error("The second argument is not a number"));
		i++;
	}
	return (0);
}

int	ft_check_int(char *stack)
{
	long long	nb;

	nb = ft_atoll(stack);
	if (nb < -2147483648 || nb > 2147483647)
		return (ft_print_error("The second argument is bigger than int"));
	if (nb < 1 || nb > 5)
		return (ft_print_error("The seconde argument must be between 1 and 5"));
	return (0);
}
