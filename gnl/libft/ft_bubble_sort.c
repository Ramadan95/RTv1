/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:41:17 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/11 17:41:42 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bubble_sort(char **a)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!a[0])
		return ;
	while (a[i])
	{
		j = i + 1;
		while (a[j])
		{
			if (ft_strcmp(a[i], a[j]) > 0)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
