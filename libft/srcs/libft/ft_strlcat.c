/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:34:20 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/30 15:36:02 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (size <= lendst)
		return (size + lensrc);
	while (src[i] && lendst + i < size - 1)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	return (lendst + lensrc);
}
