/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/22 19:13:37 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_resolution(char *str, t_config *cfg)
{
	if (cfg->w > 0 || cfg->h > 0)
	{
		ft_putstr_fd("Error\nMultiple resolution elements\n", 2);
		return (0);
	}
	str = skip_whitespaces(str + 1);
	while (ft_isdigit(*str))
	{
		cfg->w = 10 * cfg->w + *str - '0';
		str++;
	}
	str = skip_whitespaces(str);
	while (ft_isdigit(*str))
	{
		cfg->h = 10 * cfg->h + *str - '0';
		str++;
	}
	if (cfg->w <= 0 || cfg->h <= 0 || *str)
	{
		ft_putstr_fd("Error\nResolution is invalid\n", 2);
		return (0);
	}
	return (1);
}

static int	process_texture_path(char *str, t_texture *tex)
{
	if (tex->path)
	{
		ft_putstr_fd("Error\nMultiple path elements\n", 2);
		return (0);
	}
	str = skip_whitespaces(str + 2);
	if (!(tex->path = ft_strdup(str)))
	{
		ft_putstr_fd("Error\nFailed to copy wall path\n", 2);
		return (0);
	}
	return (1);
}

static int	parse_color(char *str)
{
	int		color;
	int		num;
	int		i;

	i = 1;
	color = 0;
	while (1)
	{
		str = skip_whitespaces(str);
		num = num_from_str(&str);
		if (num > 255)
			return (-1);
		color |= num;
		if (i == 3)
		{
			if (*str)
				return (-1);
			return (color);
		}
		str = skip_whitespaces(str);
		if (*(str++) != ',')
			return (-1);
		color <<= 8;
		i++;
	}
}

static int	process_color(char *str, int *color)
{
	if (*color != -1)
	{
		ft_putstr_fd("Error\nMultiple color elements\n", 2);
		return (0);
	}
	if ((*color = parse_color(str + 1)) == -1)
	{
		ft_putstr_fd("Error\nFailed to parse color\n", 2);
		return (0);
	}
	return (1);
}

int			process_elements(char *str, t_config *cfg)
{
	if (ft_strncmp(str, "R ", 2) == 0)
		return (process_resolution(str, cfg));
	else if (ft_strncmp(str, "NO ", 3) == 0)
		return (process_texture_path(str, &cfg->walls[NORTH]));
	else if (ft_strncmp(str, "SO ", 3) == 0)
		return (process_texture_path(str, &cfg->walls[SOUTH]));
	else if (ft_strncmp(str, "WE ", 3) == 0)
		return (process_texture_path(str, &cfg->walls[WEST]));
	else if (ft_strncmp(str, "EA ", 3) == 0)
		return (process_texture_path(str, &cfg->walls[EAST]));
	else if (ft_strncmp(str, "S ", 2) == 0)
		return (process_texture_path(str, &cfg->sprite));
	else if (ft_strncmp(str, "F ", 2) == 0)
		return (process_color(str, &cfg->floor_color));
	else if (ft_strncmp(str, "C ", 2) == 0)
		return (process_color(str, &cfg->ceiling_color));
	else if (ft_strlen(str) != 0)
	{
		ft_putstr_fd("Error\nInvalid element\n", 2);
		return (0);
	}
	else
		return (1);
}
