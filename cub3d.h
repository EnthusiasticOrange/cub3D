/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/19 20:10:44 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include "gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define CEILING_TYPE	0
# define FLOOR_TYPE		1

# define COLOR_NONE 0xFF000000

# define NORTH	0
# define SOUTH	1
# define WEST	2
# define EAST	3

# define X11DESTROY	17

# define KEY_W		13
# define KEY_S		1
# define KEY_A		0
# define KEY_D		2
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

typedef struct	s_texture
{
	char		*path;
	int			width;
	int			heigth;
	void		*img;
	unsigned	*data;
}				t_texture;

typedef struct	s_tex_draw
{
	t_texture	*wall;
	int			stripe;
	double		perp_dist;
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
}				t_tex_draw;

typedef struct	s_config
{
	int			w;
	int			h;
	int			floor_color;
	int			ceiling_color;
	int			map_w;
	int			map_h;
	char		**map;
	t_texture	walls[4];
	t_texture	sprite;
}				t_config;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		*z_buffer;
	t_list		*sp_list;
}				t_player;

typedef struct	s_cub3d_state
{
	void		*mlx;
	void		*win;
	t_config	cfg;
	t_player	player;
	void		*img;
	unsigned	*data;
	int			save;
}				t_cub3d_state;

typedef struct	s_visible_sprite
{
	double		x;
	double		y;
	double		d;
}				t_visible_sprite;

typedef struct	s_sprite_draw
{
	t_visible_sprite	*sprite;
	int					stripe;
	double				transform_x;
	double				transform_y;
	int					sprite_x;
	int					sprite_h;
	int					sprite_w;
	int					draw_start_x;
	int					draw_end_x;
	int					draw_start_y;
	int					draw_end_y;
	int					tex_x;
	int					tex_y;
}				t_sprite_draw;

typedef struct	s_dda
{
	double		ray_dir_x;
	double		ray_dir_u;
	double		side_d_x;
	double		side_d_y;
	double		delta_d_x;
	double		delta_d_y;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	int			side;
}				t_dda;

char			*skip_whitespaces(char *str);
int				num_from_str(char **str);
int				create_map(int fd, t_config *cfg);
int				check_map(t_config *cfg);
int				process_elements(char *str, t_config *cfg);
int				process_file(char *filename, t_config *cfg);
int				init_mlx(t_cub3d_state *state);
int				init_textures(t_cub3d_state *state);
int				init_player(t_config *cfg, t_player *player);
int				add_visible_sprite(t_player *player, double x, double y);
void			init_dda(t_dda *dda, t_config	*cfg, t_player	*player, int x);
int				perform_dda(t_dda *dda, t_config *cfg, t_player *player);
void			draw_stripe_wall(t_dda *dda, t_cub3d_state *state,
									t_tex_draw *draw);
void			draw_sprites(t_cub3d_state *state);
int				draw(t_cub3d_state *state);
int				key_hook(int keycode, t_cub3d_state *state);
int				clear_cub3d_state(t_cub3d_state *state);
int				save_bmp(t_cub3d_state *state);

#endif
