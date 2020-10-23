/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:23:16 by mjuli             #+#    #+#             */
/*   Updated: 2020/07/27 19:26:02 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		copy_from_buf(t_gnl_state *state, size_t len)
{
	char	*new_line;

	if (!(new_line = malloc(state->size + len + 1)))
	{
		if (state->line != NULL)
			free(state->line);
		state->line = NULL;
		state->size = 0;
		return (0);
	}
	if (state->line != 0)
	{
		ft_memcpy(new_line, state->line, state->size);
		free(state->line);
	}
	ft_memcpy(new_line + state->size, state->buffer + state->offset, len);
	state->line = new_line;
	state->size += len;
	state->offset += len;
	state->line[state->size] = '\0';
	return (1);
}
