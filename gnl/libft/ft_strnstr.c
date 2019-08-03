/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 07:42:17 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:36:39 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	if (!n[0])
		return (&h[i]);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j])
			j++;
		if (n[j] == '\0' && i + j <= len)
			return (&h[i]);
		i++;
	}
	return (0);
}
