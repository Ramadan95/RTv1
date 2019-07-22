/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:58:44 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:30:59 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		ft_iswspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			j;
	char			*buf;
	size_t			len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_iswspace(s[i]))
		i++;
	j = ft_strlen(s);
	while (s[i] && ft_iswspace(s[j - 1]))
		j--;
	len = j - i;
	j = 0;
	buf = (char*)malloc(sizeof(char) * len + 1);
	if (!buf)
		return (NULL);
	buf = ft_strsub(s, i, len);
	buf[len + 1] = '\0';
	return (buf);
}
