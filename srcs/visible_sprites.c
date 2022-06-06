/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/18 17:14:15 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_list	*create_new_sprite(double x, double y, double d)
{
	t_visible_sprite	*sprite;
	t_list				*item;

	if (!(sprite = malloc(sizeof(t_visible_sprite))))
	{
		ft_putstr_fd("Error\nFailed to allocate visible sprite\n", 2);
		return (0);
	}
	sprite->x = x;
	sprite->y = y;
	sprite->d = d;
	if (!(item = ft_lstnew(sprite)))
	{
		ft_putstr_fd("Error\nFailed to allocate new sprite list item\n", 2);
		return (0);
	}
	return (item);
}

static int		swap_visible_sprites(t_list *temp, double x, double y, double d)
{
	t_list				*item;
	t_visible_sprite	*sprite;

	if (!(item = ft_lstnew(temp->content)))
	{
		ft_putstr_fd("Error\nFailed to allocate new list item to swap\n", 2);
		return (0);
	}
	item->next = temp->next;
	if (!(sprite = malloc(sizeof(t_visible_sprite))))
	{
		ft_putstr_fd("Error\nFailed to allocate new list sprite to swap\n", 2);
		return (0);
	}
	sprite->x = x;
	sprite->y = y;
	sprite->d = d;
	temp->content = sprite;
	temp->next = item;
	return (1);
}

static int		insert_visible_sprite(t_list *lst, double x, double y, double d)
{
	t_visible_sprite	*item;

	while (1)
	{
		item = lst->content;
		if (item->x == x && item->y == y)
			return (1);
		if (item->d < d)
		{
			if (!swap_visible_sprites(lst, x, y, d))
				return (0);
			return (1);
		}
		else if (lst->next == NULL)
		{
			if (!(lst->next = create_new_sprite(x, y, d)))
				return (0);
			return (1);
		}
		lst = lst->next;
	}
}

int				add_visible_sprite(t_player *player, double x, double y)
{
	double				distance;

	distance = (player->pos_x - x) * (player->pos_x - x)
				+ (player->pos_y - y) * (player->pos_y - y);
	if (!player->sp_list)
	{
		if (!(player->sp_list = create_new_sprite(x, y, distance)))
			return (0);
		return (1);
	}
	if (!insert_visible_sprite(player->sp_list, x, y, distance))
		return (0);
	return (1);
}
