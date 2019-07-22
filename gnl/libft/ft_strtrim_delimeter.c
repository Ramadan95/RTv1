/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_delimeter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:52:10 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/04 16:10:12 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		ft_isdelimeter(char c, char delimeter)
{
	if (c == delimeter)
		return (1);
	return (0);
}

char			*ft_strtrim_delimeter(char const *s, char ch)
{
	unsigned int	i;
	size_t			j;
	char			*buf;
	size_t			len;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && ft_isdelimeter(s[i], ch))
		i++;
	j = ft_strlen(s);
	while (s[i] && ft_isdelimeter(s[j - 1], ch))
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
