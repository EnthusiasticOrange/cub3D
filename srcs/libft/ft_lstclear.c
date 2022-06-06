/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:40:52 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/14 20:43:44 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tail;
	t_list *temp;

	tail = *lst;
	while (tail)
	{
		temp = tail;
		tail = tail->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
