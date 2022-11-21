/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:29:13 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/30 15:42:32 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	i = 0;
	copy_s1 = (unsigned char *) s1;
	copy_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (copy_s1[i] == copy_s2[i] && i < n - 1)
		i++;
	return ((unsigned char)copy_s1[i] - (unsigned char)copy_s2[i]);
}
