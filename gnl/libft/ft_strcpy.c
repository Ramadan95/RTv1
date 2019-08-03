/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:41:04 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/04 14:28:07 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*d;
	char	*s;
	size_t	len;

	d = dst;
	s = (char *)src;
	len = ft_strlen(src);
	ft_memcpy(d, s, len);
	d[len] = '\0';
	return (d);
}
