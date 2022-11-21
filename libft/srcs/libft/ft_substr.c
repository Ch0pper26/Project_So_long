/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:23:16 by eblondee          #+#    #+#             */
/*   Updated: 2022/03/31 11:10:45 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		newstr = malloc(1 * sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > ft_strlen(s + start))
		newstr = malloc(ft_strlen(s + start) + 1 * sizeof(char));
	else
		newstr = malloc(len + 1 * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && s[start] != '\0' && i < len)
	{
		newstr[i] = s[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
