/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/22 19:12:15 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		add_map_line_to_list(char *line, t_list **lst)
{
	t_list	*temp;

	temp = ft_lstnew(line);
	if (!temp)
	{
		ft_lstclear(lst, free);
		ft_putstr_fd("Error\nFailed to alloc new list while reading map\n", 2);
		return (0);
	}
	ft_lstadd_back(lst, temp);
	return (1);
}

static t_list	*read_map(int fd, t_config *cfg)
{
	int		result;
	int		len;
	char	*str;
	t_list	*lst;

	lst = NULL;
	while ((result = get_next_line(fd, &str)) > 0)
	{
		if ((len = ft_strlen(str)) == 0 && cfg->map_h == 0 && cfg->map_w == 0)
		{
			free(str);
			continue ;
		}
		if (!add_map_line_to_list(str, &lst))
			return (0);
		cfg->map_h++;
		if (cfg->map_w < len)
			cfg->map_w = len;
	}
	if (result < 0)
		return (0);
	return (lst);
}

static int		convert_list_to_map(t_list *lst, t_config *cfg)
{
	int		i;
	int		len;

	if (!(cfg->map = malloc(cfg->map_h * sizeof(char*))))
	{
		ft_putstr_fd("Error\nFailed to allocate map\n", 2);
		return (0);
	}
	i = 0;
	while (lst)
	{
		cfg->map[i] = malloc(cfg->map_w + 1);
		if ((len = ft_strlen((char*)lst->content)) == 0)
		{
			ft_putstr_fd("Error\nMap has empty line\n", 2);
			return (0);
		}
		ft_memcpy(cfg->map[i], (char*)lst->content, len);
		if (len < cfg->map_w)
			ft_memset(cfg->map[i] + len, ' ', cfg->map_w - len);
		cfg->map[i][cfg->map_w] = '\0';
		i++;
		lst = lst->next;
	}
	return (1);
}

int				create_map(int fd, t_config *cfg)
{
	int		result;
	t_list	*lst;

	if (!(lst = read_map(fd, cfg)))
	{
		ft_putstr_fd("Error\nFailed while reading map from file\n", 2);
		return (0);
	}
	result = convert_list_to_map(lst, cfg);
	ft_lstclear(&lst, free);
	return (result);
}
