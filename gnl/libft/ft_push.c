/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:03:42 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/11 17:31:33 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_push(t_list **head, t_list *link)
{
	t_list	*tmp;

	if (head == NULL || *head == NULL || link == NULL)
		return ;
	tmp = (t_list*)malloc(sizeof(t_list));
	tmp->content = link;
	tmp->next = *head;
	(*head) = tmp;
}
