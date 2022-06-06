/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexey <alexey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2022/06/07 01:04:22 by alexey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	draw_hook(t_cub3d_state *state)
{
	draw(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img, 0, 0);
	return (0);
}

static int	init(char *filename, t_cub3d_state *state)
{
	state->cfg.floor_color = -1;
	state->cfg.ceiling_color = -1;
	if (!process_file(filename, &state->cfg))
		return (0);
	if (!check_map(&state->cfg))
		return (0);
	if (!init_player(&state->cfg, &state->player))
		return (0);
	if (!init_mlx(state))
		return (0);
	if (!init_textures(state))
		return (0);
	if (state->save)
		return (1);
	if (!(state->win = mlx_new_window(state->mlx, state->cfg.w,
										state->cfg.h, "cub3d")))
	{
		ft_putstr_fd("Error\nFailed to create window\n", 2);
		return (0);
	}
	return (1);
}

static int	start(t_cub3d_state *state)
{
	mlx_expose_hook(state->win, draw_hook, state);
	mlx_hook(state->win, 2, 0, key_hook, state);
	mlx_hook(state->win, X11DESTROY, 0, clear_cub3d_state, state);
	draw_hook(state);
	return (mlx_loop(state->mlx));
}

int			main(int argc, char **argv)
{
	static t_cub3d_state state;

	if (argc == 3)
	{
		if (ft_strlen(argv[2]) != 6 || ft_strncmp(argv[2], "--save", 6) != 0)
		{
			ft_putstr_fd("Error\nWrong second argument\n", 2);
			return (0);
		}
		state.save = 1;
	}
	else if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		return (0);
	}
	if (!init(argv[1], &state))
	{
		clear_cub3d_state(&state);
		return (0);
	}
	if (!state.save)
		return (start(&state));
	else
		return (save_bmp(&state));
}
