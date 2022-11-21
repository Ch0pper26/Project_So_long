/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:11:50 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/06 09:50:29 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	character;

	i = 0;
	character = c;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == character)
			return ((char *) s + i);
		i--;
	}
	return (NULL);
}
