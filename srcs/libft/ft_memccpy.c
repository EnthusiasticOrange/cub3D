/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:01:02 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/23 20:58:02 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dst_p;
	const char	*src_p;

	dst_p = dest;
	src_p = src;
	while (n--)
	{
		*dst_p = *src_p;
		if (*dst_p == (char)c)
			return (dst_p + 1);
		dst_p++;
		src_p++;
	}
	return (NULL);
}
