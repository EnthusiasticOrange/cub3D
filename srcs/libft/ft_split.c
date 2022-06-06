/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuli <mjuli@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 13:58:48 by mjuli             #+#    #+#             */
/*   Updated: 2020/05/23 19:59:02 by mjuli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(const char *str, char c)
{
	size_t	count;
	size_t	i;
	int		is_word;

	count = 0;
	is_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_word = 0;
		else if (is_word == 0)
		{
			count++;
			is_word = 1;
		}
		i++;
	}
	return (count);
}

static int		word_size(char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char		*copy_word(char **s, char c)
{
	char	*str;
	size_t	size;

	size = word_size(*s, c);
	str = ft_substr(*s, 0, size);
	*s += size;
	return (str);
}

static void		free_array(char **split)
{
	while (*split)
		free(split++);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;
	size_t	count;
	size_t	i;

	str = (char*)s;
	count = word_count(str, c);
	if (!(ret = malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	ret[count] = NULL;
	i = 0;
	while (i < count)
	{
		while (*str == c)
			str++;
		ret[i] = copy_word(&str, c);
		if (!ret[i])
		{
			free_array(ret);
			free(ret);
			return (NULL);
		}
		i++;
	}
	return (ret);
}
