/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:32:43 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/22 19:15:20 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_screen_img(t_cub3d_state *state)
{
	int bps;
	int size_line;
	int endian;
	int sizex;
	int sizey;

	mlx_get_screen_size(state->mlx, &sizex, &sizey);
	state->cfg.w = state->cfg.w > sizex ? sizex : state->cfg.w;
	state->cfg.h = state->cfg.h > sizey ? sizey : state->cfg.h;
	if (!(state->img = mlx_new_image(state->mlx, state->cfg.w, state->cfg.h)))
	{
		ft_putstr_fd("Error\nFailed to init screen img\n", 2);
		return (0);
	}
	state->data = (unsigned int*)mlx_get_data_addr(state->img, &bps,
													&size_line, &endian);
	return (1);
}

int			init_mlx(t_cub3d_state *state)
{
	if (!(state->mlx = mlx_init()))
	{
		ft_putstr_fd("Error\nFailed to init mlx\n", 2);
		return (0);
	}
	if (!init_screen_img(state))
		return (0);
	if (!(state->player.z_buffer = malloc(sizeof(double) * state->cfg.w)))
	{
		ft_putstr_fd("Error\nFailed to allocate ZBuffer\n", 2);
		return (0);
	}
	return (1);
}

static int	load_texture(t_cub3d_state *state, t_texture *tex)
{
	int bps;
	int sl;
	int end;

	if (!(tex->img = mlx_xpm_file_to_image(state->mlx, tex->path,
												&tex->width, &tex->heigth)))
		return (0);
	tex->data = (unsigned*)mlx_get_data_addr(tex->img, &bps, &sl, &end);
	return (1);
}

int			init_textures(t_cub3d_state *state)
{
	int			i;
	t_texture	*tex;

	i = 0;
	while (i < 4)
	{
		tex = &state->cfg.walls[i];
		if (!load_texture(state, tex))
		{
			ft_putstr_fd("Error\nFailed to load wall texture\n", 2);
			return (0);
		}
		i++;
	}
	tex = &state->cfg.sprite;
	if (!load_texture(state, tex))
	{
		ft_putstr_fd("Error\nFailed to load sprite texture\n", 2);
		return (0);
	}
	return (1);
}
