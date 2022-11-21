/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:46:35 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/30 18:01:19 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointeur;

	if (nmemb > 2147483647 && size > 2147483647)
		return (NULL);
	pointeur = malloc(nmemb * size);
	if (pointeur == NULL || (nmemb * size) > 2147483647)
		return (NULL);
	ft_bzero(pointeur, size * nmemb);
	return (pointeur);
}
