/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:50:52 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/13 09:53:23 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*copy;
	const char	*copy_src;
	char		*endd;
	const char	*ends;

	copy = dest;
	copy_src = src;
	if (dest == NULL && src == NULL)
		return (dest);
	endd = copy + (n - 1);
	ends = copy_src + (n - 1);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n != 0)
		{
			*endd = *ends;
			endd--;
			ends--;
			n--;
		}
	}
	return (dest);
}
