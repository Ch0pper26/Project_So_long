/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:51:14 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/30 16:03:40 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t		j;
	size_t		i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
