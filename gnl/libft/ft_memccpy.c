/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:55:54 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:20:29 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*d;
	unsigned char	*s;
	unsigned char	ch;

	d = dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n)
	{
		if (ch == *s)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
		n--;
	}
	return (0);
}
