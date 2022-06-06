/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:31:07 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/14 17:34:28 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*res_str;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res_str = malloc(len_s1 + len_s2 + 1);
	if (res_str)
	{
		ft_memcpy(res_str, s1, len_s1);
		ft_memcpy(res_str + len_s1, s2, len_s2 + 1);
	}
	return (res_str);
}
