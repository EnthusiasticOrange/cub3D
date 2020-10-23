/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/19 20:24:15 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->plane_y = 0.66;
		player->dir_x = -1;
	}
	else if (dir == 'S')
	{
		player->plane_y = -0.66;
		player->dir_x = 1;
	}
	else if (dir == 'W')
	{
		player->plane_x = -0.66;
		player->dir_y = -1;
	}
	else
	{
		player->plane_x = 0.66;
		player->dir_y = 1;
	}
}

static int	set_player(t_config *cfg, t_player *player, int x, int y)
{
	if (player->pos_x != 0)
	{
		ft_putstr_fd("Error\nMultiple player positions\n", 2);
		return (0);
	}
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	set_player_dir(player, cfg->map[x][y]);
	cfg->map[x][y] = '0';
	return (1);
}

int			init_player(t_config *cfg, t_player *player)
{
	int x;
	int y;

	x = 1;
	while (x < cfg->map_h - 1)
	{
		y = 1;
		while (y < cfg->map_w - 1)
		{
			if (cfg->map[x][y] == 'N' || cfg->map[x][y] == 'S'
				|| cfg->map[x][y] == 'W' || cfg->map[x][y] == 'E')
			{
				if (!set_player(cfg, player, x, y))
					return (0);
			}
			y++;
		}
		x++;
	}
	if (player->pos_x == 0)
	{
		ft_putstr_fd("Error\nNo player position\n", 2);
		return (0);
	}
	return (1);
}
