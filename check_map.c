/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/18 17:18:06 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		check_border(t_config *cfg)
{
	int i;

	i = 0;
	while (i < cfg->map_w)
	{
		if (cfg->map[0][i] != '1' && cfg->map[0][i] != ' ')
			return (0);
		if (cfg->map[cfg->map_h - 1][i] != '1'
			&& cfg->map[cfg->map_h - 1][i] != ' ')
			return (0);
		i++;
	}
	i = 0;
	while (i < cfg->map_h)
	{
		if (cfg->map[i][0] != '1' && cfg->map[i][0] != ' ')
			return (0);
		if (cfg->map[i][cfg->map_w - 1] != '1'
			&& cfg->map[i][cfg->map_w - 1] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static	int		check_inside(t_config *cfg)
{
	int		i;
	int		j;
	char	c;

	c = ' ';
	i = 1;
	while (i < cfg->map_h - 1)
	{
		j = 1;
		while (j < cfg->map_w - 1)
		{
			if (cfg->map[i][j] != '1' && cfg->map[i][j] != c)
				if (cfg->map[i - 1][j - 1] == c || cfg->map[i - 1][j] == c
					|| cfg->map[i - 1][j + 1] == c || cfg->map[i][j - 1] == c
					|| cfg->map[i - 1][j + 1] == c
					|| cfg->map[i + 1][j - 1] == c
					|| cfg->map[i + 1][j] == c || cfg->map[i + 1][j + 1] == c)
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		check_map_symbols(t_config *cfg)
{
	int	i;
	int	j;

	i = 0;
	while (i < cfg->map_h)
	{
		j = 1;
		while (j < cfg->map_w)
		{
			if (cfg->map[i][j] != ' ' && cfg->map[i][j] != '1'
				&& cfg->map[i][j] != '0' && cfg->map[i][j] != '2'
				&& cfg->map[i][j] != 'N' && cfg->map[i][j] != 'S'
				&& cfg->map[i][j] != 'E' && cfg->map[i][j] != 'W')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				check_map(t_config *cfg)
{
	if (!check_border(cfg))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_inside(cfg))
	{
		ft_putstr_fd("Error\nMap is not surrounded by walls\n", 2);
		return (0);
	}
	if (!check_map_symbols(cfg))
	{
		ft_putstr_fd("Error\nMap has invalid symbols\n", 2);
		return (0);
	}
	return (1);
}
