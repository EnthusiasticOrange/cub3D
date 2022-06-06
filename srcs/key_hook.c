/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:07:16 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/19 20:30:56 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move(t_cub3d_state *state, int dir, double ms)
{
	t_config	*cfg;
	t_player	*p;

	cfg = &state->cfg;
	p = &state->player;
	if (cfg->map[(int)(p->pos_x + dir * p->dir_x * ms)][(int)p->pos_y] == '0')
		p->pos_x += dir * p->dir_x * ms;
	if (cfg->map[(int)p->pos_x][(int)(p->pos_y + dir * p->dir_y * ms)] == '0')
		p->pos_y += dir * p->dir_y * ms;
}

static void	strafe(t_cub3d_state *state, int dir, double ms)
{
	t_config	*cfg;
	t_player	*p;

	cfg = &state->cfg;
	p = &state->player;
	if (cfg->map[(int)(p->pos_x + dir * p->plane_x * ms)][(int)p->pos_y] == '0')
		p->pos_x += dir * p->plane_x * ms;
	if (cfg->map[(int)p->pos_x][(int)(p->pos_y + dir * p->plane_y * ms)] == '0')
		p->pos_y += dir * p->plane_y * ms;
}

static void	rotate(t_cub3d_state *state, double dir, double ms)
{
	t_player	*p;
	double		old_dir_x;
	double		old_plane_x;

	p = &state->player;
	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(ms * dir) - p->dir_y * sin(ms * dir);
	p->dir_y = old_dir_x * sin(ms * dir) + p->dir_y * cos(ms * dir);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(ms * dir) - p->plane_y * sin(ms * dir);
	p->plane_y = old_plane_x * sin(ms * dir) + p->plane_y * cos(ms * dir);
}

int			key_hook(int keycode, t_cub3d_state *state)
{
	double move_speed;
	double rot_speed;

	move_speed = 0.2;
	rot_speed = 0.05;
	if (keycode == KEY_W)
		move(state, 1, move_speed);
	if (keycode == KEY_S)
		move(state, -1, move_speed);
	if (keycode == KEY_D)
		strafe(state, 1, move_speed);
	if (keycode == KEY_A)
		strafe(state, -1, move_speed);
	if (keycode == KEY_RIGHT)
		rotate(state, -1, rot_speed);
	if (keycode == KEY_LEFT)
		rotate(state, 1, rot_speed);
	if (keycode == KEY_ESC)
		clear_cub3d_state(state);
	draw(state);
	mlx_put_image_to_window(state->mlx, state->win, state->img, 0, 0);
	return (0);
}
