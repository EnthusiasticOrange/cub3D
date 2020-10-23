/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_cub3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:52:14 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/19 21:17:22 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	clear_texture(t_cub3d_state *state, t_texture *tex)
{
	if (tex->path)
		free(tex->path);
	if (tex->img)
		mlx_destroy_image(state->mlx, tex->img);
}

static void	clear_config(t_cub3d_state *state)
{
	t_config *cfg;

	cfg = &state->cfg;
	if (cfg->map)
	{
		while (cfg->map_h > 0)
		{
			free(cfg->map[cfg->map_h - 1]);
			cfg->map_h--;
		}
		free(cfg->map);
	}
	clear_texture(state, &cfg->walls[NORTH]);
	clear_texture(state, &cfg->walls[SOUTH]);
	clear_texture(state, &cfg->walls[EAST]);
	clear_texture(state, &cfg->walls[WEST]);
	clear_texture(state, &cfg->sprite);
}

int			clear_cub3d_state(t_cub3d_state *state)
{
	if (state->mlx && state->win)
		mlx_destroy_window(state->mlx, state->win);
	if (state->mlx && state->img)
		mlx_destroy_image(state->mlx, state->img);
	clear_config(state);
	if (state->player.z_buffer != NULL)
		free(state->player.z_buffer);
	ft_lstclear(&state->player.sp_list, free);
	exit(0);
}
