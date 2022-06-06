/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:45:49 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 16:57:45 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_p;
	char		*dst_p;

	dst_p = dest;
	src_p = src;
	if (dst_p < src_p)
		while (n--)
			*dst_p++ = *src_p++;
	else
	{
		dst_p += n - 1;
		src_p += n - 1;
		while (n--)
			*dst_p-- = *src_p--;
	}
	return (dest);
}
