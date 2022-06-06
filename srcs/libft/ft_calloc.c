/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burningram <burningram@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:41:52 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/27 14:36:11 by burningram       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ret_ptr;

	ret_ptr = malloc(nmemb * size);
	if (ret_ptr)
		ft_bzero(ret_ptr, nmemb * size);
	return (ret_ptr);
}
