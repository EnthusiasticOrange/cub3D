/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 10:50:09 by mjuli             #+#    #+#             */
/*   Updated: 2020/10/21 18:54:45 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_whitespaces(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			break ;
		str++;
	}
	return (str);
}

int		num_from_str(char **str)
{
	int num;

	num = 0;
	if (!ft_isdigit(**str))
		return (256);
	while (ft_isdigit(**str))
	{
		num = num * 10 + **str - '0';
		(*str)++;
	}
	return (num);
}
