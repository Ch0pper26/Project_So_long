/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:52:19 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/13 09:58:04 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	char	*copie;

	i = ft_strlen(s);
	j = 0;
	copie = malloc(sizeof(char) * (i + 1));
	if (copie == NULL)
		return (NULL);
	while (j < i)
	{
		copie[j] = s[j];
		j++;
	}
	copie[j] = '\0';
	return (copie);
}
