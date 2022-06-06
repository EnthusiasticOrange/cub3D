/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:46:12 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 20:07:39 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if (*s == (char)c)
		ret = s;
	return ((char*)ret);
}
