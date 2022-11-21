/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:49:45 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/02 15:50:14 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

// retourne la taille du tableau en comptant le NULL
static int	count_split(const char *s, char c)
{
	size_t	i;
	int		size;

	i = 0;
	size = 1;
	while (s[i] && s[i] == c)
		i++;
	if (s[i] == '\0')
		return (size);
	while (s[i] != '\0')
	{
		if (s[i] == c && (i != (ft_strlen(s) - 1) && s[i + 1] != c))
			size++;
		i++;
	}
	return (size + 1);
}

static char	**fill_tab(char const *s, char c, char **tab)
{
	size_t	j;
	size_t	k;
	char	*tmp;

	j = 0;
	tmp = (char *)s;
	while (*tmp != '\0')
	{
		if (*tmp == c)
			tmp++;
		else
		{
			k = 0;
			while (tmp[k] && tmp[k] != c)
				k++;
			tab[j] = malloc(sizeof(char) * ((&tmp[k] - tmp) + 1));
			ft_strlcpy(tab[j], tmp, (&tmp[k] - tmp + 1));
			tmp = tmp + k;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	tab = malloc(sizeof(char *) * count_split(s, c));
	if (!tab)
		return (NULL);
	else
		return (fill_tab(s, c, tab));
}
