/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 01:52:20 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:24:02 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;

	src = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n)
	{
		if (*src == ch)
			return (src);
		src++;
		n--;
	}
	return (0);
}
