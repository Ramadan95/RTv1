/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:41:44 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/04 16:00:30 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_pow(int a, int pow)
{
	int				i;
	long long int	value;

	i = 1;
	value = i;
	if (pow > 0)
		while (i++ < pow)
			value *= a;
	else
	{
		if (pow == 0)
			value = 1;
		else
			value = 0;
	}
	return (value);
}
