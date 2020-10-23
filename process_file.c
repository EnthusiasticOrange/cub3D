/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/20 18:35:52 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file_extension(char *filename)
{
	char	*ext;

	if (!(ext = ft_strrchr(filename, '/')))
		ext = filename;
	if ((ext = ft_strrchr(ext + 1, '.')))
	{
		if (ft_strlen(ext) == 4 && ft_strncmp(ext, ".cub", 4) == 0)
			return (1);
	}
	ft_putstr_fd("Error\nWrong file extension\n", 2);
	return (0);
}

static int	check_elements_complete(t_config *cfg)
{
	if (cfg->w > 0 && cfg->h > 0
		&& cfg->walls[NORTH].path != NULL && cfg->walls[SOUTH].path != NULL
		&& cfg->walls[WEST].path != NULL && cfg->walls[EAST].path != NULL
		&& cfg->sprite.path != NULL
		&& cfg->floor_color >= 0 && cfg->ceiling_color >= 0)
		return (1);
	else
		return (0);
}

static int	read_file(int fd, t_config *cfg)
{
	int		result;
	char	*str;

	while (get_next_line(fd, &str) > 0)
	{
		result = process_elements(str, cfg);
		free(str);
		if (result == 0)
			return (0);
		if (check_elements_complete(cfg))
		{
			if (create_map(fd, cfg))
				return (1);
			else
				return (0);
		}
	}
	ft_putstr_fd("Error\nUnexpected end of file\n", 2);
	return (0);
}

int			process_file(char *filename, t_config *cfg)
{
	int fd;
	int result;

	if (!check_file_extension(filename))
		return (0);
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nFailed to open .cub file\n", 2);
		return (0);
	}
	result = read_file(fd, cfg);
	close(fd);
	return (result);
}
