/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:03:52 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/08 12:01:55 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*buff;

	if (lst == NULL)
		return ;
	buff = *lst;
	while (buff != NULL)
	{
		tmp = buff->next;
		ft_lstdelone(buff, del);
		buff = tmp;
	}
	*lst = NULL;
}
