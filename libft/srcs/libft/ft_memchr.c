/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:57:37 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/05 17:50:02 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*search;
	unsigned char	character;

	character = (unsigned char)c;
	search = (unsigned char *)s;
	while (n != 0)
	{
		if (*search == character)
			return ((char *)search);
		search++;
		n--;
	}
	return (NULL);
}
