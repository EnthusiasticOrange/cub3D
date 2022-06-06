/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:47:19 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/20 19:57:18 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	compute_transform(t_player *pl, t_sprite_draw *draw)
{
	double x;
	double y;
	double inv_det;

	x = draw->sprite->x - pl->pos_x;
	y = draw->sprite->y - pl->pos_y;
	inv_det = 1.0 / (pl->plane_x * pl->dir_y - pl->dir_x * pl->plane_y);
	draw->transform_x = inv_det * (pl->dir_y * x - pl->dir_x * y);
	draw->transform_y = inv_det * (-pl->plane_y * x + pl->plane_x * y);
}

static void	compute_sprite_visible(t_config *cfg, t_sprite_draw *draw)
{
	draw->sprite_x = (cfg->w / 2) * (1 + draw->transform_x / draw->transform_y);
	draw->sprite_h = abs((int)(cfg->h / (draw->transform_y)));
	draw->draw_start_y = -draw->sprite_h / 2 + cfg->h / 2;
	if (draw->draw_start_y < 0)
		draw->draw_start_y = 0;
	draw->draw_end_y = draw->sprite_h / 2 + cfg->h / 2;
	if (draw->draw_end_y >= cfg->h)
		draw->draw_end_y = cfg->h;
	draw->sprite_w = abs((int)(cfg->w / (draw->transform_y)));
	draw->draw_start_x = -draw->sprite_w / 2 + draw->sprite_x;
	if (draw->draw_start_x < 0)
		draw->draw_start_x = 0;
	draw->draw_end_x = draw->sprite_w / 2 + draw->sprite_x;
	if (draw->draw_end_x >= cfg->w)
		draw->draw_end_x = cfg->w;
}

static void	draw_stripe(t_cub3d_state *state, t_sprite_draw *draw)
{
	int				y;
	int				d;
	unsigned int	color;

	y = draw->draw_start_y;
	while (y < draw->draw_end_y)
	{
		d = y - state->cfg.h / 2 + draw->sprite_h / 2;
		draw->tex_y = ((d * state->cfg.sprite.heigth) / draw->sprite_h);
		color = state->cfg.sprite.data[state->cfg.sprite.width
										* draw->tex_y + draw->tex_x];
		if (color != COLOR_NONE)
			state->data[y * state->cfg.w + draw->stripe] = color;
		y++;
	}
}

void		draw_sprites(t_cub3d_state *state)
{
	t_sprite_draw	draw;
	t_list			*lst;
	int				x;

	lst = state->player.sp_list;
	while (lst)
	{
		draw.sprite = lst->content;
		compute_transform(&state->player, &draw);
		compute_sprite_visible(&state->cfg, &draw);
		x = draw.draw_start_x;
		while (x < draw.draw_end_x)
		{
			draw.stripe = x;
			draw.tex_x = ((x - (-draw.sprite_w / 2 + draw.sprite_x))
							* state->cfg.sprite.width / draw.sprite_w);
			if (draw.transform_y > 0 && x > 0 && x < state->cfg.w
				&& draw.transform_y < state->player.z_buffer[draw.stripe])
				draw_stripe(state, &draw);
			x++;
		}
		lst = lst->next;
	}
	ft_lstclear(&state->player.sp_list, free);
}
