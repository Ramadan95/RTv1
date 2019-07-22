/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 05:46:00 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:34:31 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*h;
	char	*n;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	if (!n[0])
		return (&h[i]);
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && n[j])
			j++;
		if (n[j] == '\0')
			return (&h[i]);
		i++;
	}
	return (0);
}
