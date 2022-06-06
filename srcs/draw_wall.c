/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:28:47 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/18 16:52:51 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*choose_wall(t_dda *dda, t_config *cfg, t_player *player)
{
	if (!dda->side)
	{
		if (dda->map_x > player->pos_x)
			return (&cfg->walls[NORTH]);
		else
			return (&cfg->walls[SOUTH]);
	}
	else
	{
		if (dda->map_y > player->pos_y)
			return (&cfg->walls[WEST]);
		else
			return (&cfg->walls[EAST]);
	}
}

static void			compute_tex_x(t_dda *dda, t_player *pl, t_tex_draw *draw)
{
	double		wall_x;

	if (dda->side == 0)
		wall_x = pl->pos_y + draw->perp_dist * dda->ray_dir_u;
	else
		wall_x = pl->pos_x + draw->perp_dist * dda->ray_dir_x;
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * (double)draw->wall->width);
	if (dda->side == 0 && dda->ray_dir_x > 0)
		draw->tex_x = draw->wall->width - draw->tex_x - 1;
	if (dda->side == 1 && dda->ray_dir_u < 0)
		draw->tex_x = draw->wall->width - draw->tex_x - 1;
}

void				draw_stripe_wall(t_dda *dda, t_cub3d_state *state,
										t_tex_draw *draw)
{
	int		y;
	double	step;
	double	tex_pos;

	draw->wall = choose_wall(dda, &state->cfg, &state->player);
	compute_tex_x(dda, &state->player, draw);
	step = (double)draw->wall->heigth / (double)draw->line_h;
	tex_pos = (draw->draw_start - state->cfg.h / 2 + draw->line_h / 2) * step;
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		draw->tex_y = (int)tex_pos & (draw->wall->heigth - 1);
		tex_pos += step;
		state->data[y * state->cfg.w + draw->stripe] =
			draw->wall->data[draw->tex_y * draw->wall->width + draw->tex_x];
		y++;
	}
}
