/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <eblondee@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:02:42 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/30 11:17:24 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_len_split_with_null(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		i++;
	}
	return (i + 1);
}

int	ft_len_split_no_null(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		i++;
	}
	return (i);
}
