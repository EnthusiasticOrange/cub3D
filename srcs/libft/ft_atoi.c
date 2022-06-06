/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:48:56 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/12 20:31:39 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int ret_num;
	int minus;

	minus = 1;
	ret_num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		minus = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		ret_num = ret_num * 10;
		if (minus == 1)
			ret_num += *str++ - '0';
		else
			ret_num -= *str++ - '0';
	}
	return (ret_num);
}
