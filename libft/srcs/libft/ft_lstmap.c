/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:16:01 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:14 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	start = ft_lstnew((*f)(lst->content));
	if (start == NULL)
		return (NULL);
	tmp = tmp->next;
	while (tmp != NULL)
	{
		new_lst = ft_lstnew((*f)(tmp->content));
		if (new_lst == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_lst);
		tmp = tmp->next;
	}
	new_lst = NULL;
	return (start);
}
