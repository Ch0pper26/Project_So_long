/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:15:38 by eblondee          #+#    #+#             */
/*   Updated: 2022/05/04 11:27:15 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (s_1[i] == s_2[i] && s_1[i] != '\0' && s_2[i] != '\0')
	{
		i++;
	}
	return (s_1[i] - s_2[i]);
}
