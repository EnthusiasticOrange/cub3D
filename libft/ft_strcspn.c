/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:57:44 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/14 17:58:15 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str1, const char *str2)
{
	size_t	len;

	len = 0;
	while (*str1 && !ft_strchr(str2, *str1++))
		len++;
	return (len);
}
