/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:50:39 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/21 21:23:09 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	**tail;

	new_lst = NULL;
	tail = &new_lst;
	while (lst)
	{
		if (!(*tail = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, del);
			break ;
		}
		tail = &(*tail)->next;
		lst = lst->next;
	}
	return (new_lst);
}
