/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 19:30:27 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/14 20:03:33 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if ((ret = ft_strdup(s)))
	{
		i = 0;
		while (ret[i])
		{
			ret[i] = f(i, ret[i]);
			i++;
		}
	}
	return (ret);
}
