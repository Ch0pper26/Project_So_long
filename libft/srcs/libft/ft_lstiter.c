/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eblondee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:03:27 by eblondee          #+#    #+#             */
/*   Updated: 2022/04/08 12:14:52 by eblondee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ashes.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return ;
	while (tmp != NULL)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
