/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:51:28 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/11 17:49:17 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while (*alst != NULL)
	{
		next = ((*alst)->next);
		ft_lstdelone(alst, del);
		*alst = next;
	}
}
