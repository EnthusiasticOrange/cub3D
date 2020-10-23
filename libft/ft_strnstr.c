/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:56:00 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 18:30:04 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t find_len;

	find_len = ft_strlen(to_find);
	if (!find_len)
		return (str);
	if (ft_strlen(str) < find_len)
		return (NULL);
	while (len-- >= find_len)
	{
		if (!ft_strncmp(str, to_find, find_len))
			return (str);
		str++;
	}
	return (NULL);
}
