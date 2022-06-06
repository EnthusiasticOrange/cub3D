/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/19 19:49:28 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			draw_stripe_color(t_cub3d_state *state, t_tex_draw *draw,
										int type)
{
	int y;
	int	end;
	int	color;

	y = type == CEILING_TYPE ? 0 : draw->draw_end;
	end = type == CEILING_TYPE ? draw->draw_start : state->cfg.h;
	color = type == CEILING_TYPE ? state->cfg.ceiling_color
									: state->cfg.floor_color;
	while (y < end)
	{
		state->data[y * state->cfg.w
					+ draw->stripe] = mlx_get_color_value(state->mlx, color);
		y++;
	}
}

static double		compute_wall_distance(t_dda *dda, t_player *pl)
{
	double dist;

	if (dda->side == 0)
		dist = (dda->map_x - pl->pos_x + (1 - dda->step_x) / 2)
				/ dda->ray_dir_x;
	else
		dist = (dda->map_y - pl->pos_y + (1 - dda->step_y) / 2)
				/ dda->ray_dir_u;
	if (dist < 0.000001 && dist > -0.000001)
		dist = 1;
	return (dist);
}

static void			draw_stripe(t_dda *dda, t_cub3d_state *state, int stripe)
{
	t_tex_draw draw;

	draw.stripe = stripe;
	draw.perp_dist = compute_wall_distance(dda, &state->player);
	state->player.z_buffer[stripe] = draw.perp_dist;
	draw.line_h = (int)(state->cfg.h / draw.perp_dist);
	draw.draw_start = -draw.line_h / 2 + state->cfg.h / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.line_h / 2 + state->cfg.h / 2;
	if (draw.draw_end >= state->cfg.h)
		draw.draw_end = state->cfg.h - 1;
	draw_stripe_color(state, &draw, CEILING_TYPE);
	draw_stripe_wall(dda, state, &draw);
	draw_stripe_color(state, &draw, FLOOR_TYPE);
}

int					draw(t_cub3d_state *state)
{
	t_dda	dda;
	int		x;

	x = 0;
	while (x < state->cfg.w)
	{
		init_dda(&dda, &state->cfg, &state->player, x);
		if (!perform_dda(&dda, &state->cfg, &state->player))
			return (0);
		draw_stripe(&dda, state, x);
		x++;
	}
	draw_sprites(state);
	return (1);
}
