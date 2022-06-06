/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:17:19 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/14 17:29:32 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	str_len;
	char	*substr;

	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	str_len -= start;
	s += start;
	if (len >= str_len)
		return (ft_strdup(s));
	substr = malloc(len + 1);
	if (substr)
	{
		ft_memcpy(substr, s, len);
		substr[len] = '\0';
	}
	return (substr);
}
