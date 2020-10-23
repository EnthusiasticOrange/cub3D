/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/18 16:46:59 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dda_step(t_dda *dda, t_player *player)
{
	if (dda->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_d_x = (player->pos_x - dda->map_x) * dda->delta_d_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_d_x = (dda->map_x + 1.0 - player->pos_x) * dda->delta_d_x;
	}
	if (dda->ray_dir_u < 0)
	{
		dda->step_y = -1;
		dda->side_d_y = (player->pos_y - dda->map_y) * dda->delta_d_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_d_y = (dda->map_y + 1.0 - player->pos_y) * dda->delta_d_y;
	}
}

void		init_dda(t_dda *dda, t_config *cfg, t_player *player, int x)
{
	double camer_x;

	camer_x = 2 * x / (double)cfg->w - 1;
	dda->ray_dir_x = player->dir_x + player->plane_x * camer_x;
	dda->ray_dir_u = player->dir_y + player->plane_y * camer_x;
	dda->delta_d_x = fabs(1 / dda->ray_dir_x);
	dda->delta_d_y = fabs(1 / dda->ray_dir_u);
	dda->map_x = player->pos_x;
	dda->map_y = player->pos_y;
	init_dda_step(dda, player);
}

int			perform_dda(t_dda *dda, t_config *cfg, t_player *player)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side_d_x < dda->side_d_y)
		{
			dda->side_d_x += dda->delta_d_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_d_y += dda->delta_d_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (cfg->map[dda->map_x][dda->map_y] == '1')
			hit = 1;
		else if (cfg->map[dda->map_x][dda->map_y] == '2')
			if (!add_visible_sprite(player, dda->map_x + 0.5, dda->map_y + 0.5))
				return (0);
	}
	return (1);
}
