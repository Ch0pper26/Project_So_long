/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:14:30 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/31 13:30:35 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

static	int	check(char letter, char const *check)
{
	size_t	i;

	i = 0;
	while (check[i])
	{
		if (check[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	while (check(s1[i], set) == 1)
		i++;
	while (check(s1[j - 1], set) == 1)
		j--;
	str = ft_substr(s1, i, (j - i));
	return (str);
}
