/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 13:03:46 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 18:04:27 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t src_len;
	size_t dst_len;

	j = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len > size)
		dst_len = size;
	if (dst_len == size)
		return (src_len + size);
	while (src[j] && j < size - dst_len - 1)
	{
		dst[dst_len + j] = src[j];
		j++;
	}
	if (j + dst_len < size)
		dst[dst_len + j] = '\0';
	return (src_len + dst_len);
}
