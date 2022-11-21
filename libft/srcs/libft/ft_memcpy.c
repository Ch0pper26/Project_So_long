/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:38:05 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/29 11:10:32 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*copy;
	const char	*copy_src;

	copy = (char *)dest;
	copy_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n != 0)
	{
		*copy = *copy_src;
		copy++;
		copy_src++;
		n--;
	}
	return (dest);
}
