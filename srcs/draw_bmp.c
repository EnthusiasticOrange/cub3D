/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:05:54 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/20 18:35:09 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	write_header(int fd, t_config *cfg)
{
	unsigned char	header[54];
	unsigned		filesize;
	unsigned short	bitcount;
	unsigned		header_value;

	ft_memset(header, 0, 54);
	bitcount = 32;
	filesize = 54 + cfg->w * cfg->h;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &filesize, 4);
	header_value = 54;
	ft_memcpy(header + 10, &header_value, 4);
	header_value = 40;
	ft_memcpy(header + 14, &header_value, 4);
	ft_memcpy(header + 18, &cfg->w, 4);
	ft_memcpy(header + 22, &cfg->h, 4);
	header_value = 1;
	ft_memcpy(header + 26, &header_value, 2);
	ft_memcpy(header + 28, &bitcount, 2);
	filesize -= 54;
	ft_memcpy(header + 34, &filesize, 4);
	write(fd, header, 54);
	return (1);
}

int			save_bmp(t_cub3d_state *state)
{
	int	fd;
	int	row;

	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY,
					S_IRWXU | S_IRWXG | S_IRWXO)) == -1)
	{
		ft_putstr_fd("Error\nFailed to open screenshot.bmp\n", 2);
		return (0);
	}
	write_header(fd, &state->cfg);
	if (!draw(state))
	{
		clear_cub3d_state(state);
		return (1);
	}
	row = state->cfg.h - 1;
	while (row >= 0)
	{
		write(fd, state->data + row * state->cfg.w, 4 * state->cfg.w);
		row--;
	}
	close(fd);
	clear_cub3d_state(state);
	return (1);
}
