/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 10:07:09 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/02 13:34:23 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*sign;
	char	ch;
	char	*a;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	a = (char *)s;
	ch = (char)c;
	sign = 0;
	while (i <= len)
	{
		if (ft_strchr(a, c) != 0)
			sign = ft_strchr(a, c);
		a++;
		i++;
	}
	return (sign);
}
