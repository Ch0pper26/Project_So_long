/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:56:06 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/02 15:50:25 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	character;

	character = c;
	while (*s != character)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *) s);
}
