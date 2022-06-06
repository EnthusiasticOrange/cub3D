/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:21:03 by mjuli             #+#    #+#             */
/*   Updated: 2020/07/27 19:26:09 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		gnl_state_init(t_gnl_state *state, int fd)
{
	if (!state->is_initialized || state->fd != fd)
	{
		state->fd = fd;
		state->offset = BUFFER_SIZE;
		state->bytes_read = BUFFER_SIZE;
		state->is_initialized = 1;
	}
	state->line = NULL;
	state->size = 0;
	state->end_found = 0;
}

int			gnl_state_update(t_gnl_state *state)
{
	char	*end_line;
	size_t	len;

	if (state->offset == state->bytes_read)
	{
		state->offset = 0;
		state->bytes_read = read(state->fd, state->buffer, BUFFER_SIZE);
		if (state->bytes_read == -1)
			return (0);
		else if (state->bytes_read == 0)
		{
			state->end_found = 1;
			return (1);
		}
	}
	len = state->bytes_read - state->offset;
	end_line = ft_memchr(state->buffer + state->offset, '\n', len);
	if (end_line)
	{
		len = end_line - (state->buffer + state->offset);
		state->end_found = 1;
	}
	if (!copy_from_buf(state, len))
		return (0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl_state	state;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (-1);
	gnl_state_init(&state, fd);
	while (1)
	{
		if (!gnl_state_update(&state))
			return (-1);
		if (state.end_found)
		{
			if (state.bytes_read > state.offset)
				state.offset++;
			*line = state.line;
			if (state.size == 0 && state.line == NULL)
				return (0);
			else
				return (1);
		}
	}
	return (0);
}
