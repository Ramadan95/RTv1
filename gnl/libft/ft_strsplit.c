/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:24:41 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/04 14:41:01 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_count_words(char const *s, char delimeter)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == delimeter)
			flag = 0;
		if (flag == 0 && *s != delimeter)
		{
			flag = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_count_word(char const *s, char delimeter)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == delimeter && s[i])
			i++;
		while (s[i] != delimeter && s[i])
		{
			count++;
			i++;
		}
		return (i);
	}
	return (0);
}

static	void	ft_my_free(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count_words;
	char	**buf;

	if (!s)
		return (NULL);
	i = 0;
	count_words = ft_count_words((const char *)s, c);
	if (!(buf = (char **)malloc(sizeof(*buf) * \
	(ft_count_words((const char *)s, c) + 1))))
		return (NULL);
	while (count_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(buf[i] = ft_strsub(s, 0, ft_count_word(s, c))))
		{
			ft_my_free(buf, i);
			return (NULL);
		}
		s = s + ft_count_word(s, c);
		i++;
	}
	buf[i] = NULL;
	return (buf);
}
