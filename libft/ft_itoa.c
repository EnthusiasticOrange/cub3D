/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 14:53:49 by exam              #+#    #+#             */
/*   Updated: 2020/05/14 20:01:51 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_size(int nb)
{
	size_t size;

	size = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		size++;
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*ret;
	size_t	size;
	size_t	i;
	int		minus;

	size = number_size(n);
	if ((ret = malloc(size + 1)))
	{
		minus = 1;
		i = 0;
		if (n < 0)
			minus = -1;
		while (i < size)
		{
			ret[size - i - 1] = (n % 10) * minus + '0';
			i++;
			n /= 10;
		}
		if (minus == -1)
			ret[0] = '-';
		ret[size] = '\0';
	}
	return (ret);
}
