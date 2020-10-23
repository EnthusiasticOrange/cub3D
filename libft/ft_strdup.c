/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:44:30 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 19:41:19 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		size;
	char		*ret_str;

	size = ft_strlen(s) + 1;
	ret_str = (char *)malloc(size);
	if (ret_str)
		ft_memcpy(ret_str, s, size);
	return (ret_str);
}
