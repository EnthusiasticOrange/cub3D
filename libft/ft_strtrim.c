/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:42 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/19 22:07:07 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res_str;
	size_t	str_len;
	size_t	start_len;

	str_len = ft_strlen(s1);
	start_len = ft_strspn(s1, set);
	while (str_len && ft_strchr(set, s1[str_len - 1]))
		str_len--;
	str_len -= start_len;
	res_str = ft_substr(s1, start_len, str_len);
	return (res_str);
}
