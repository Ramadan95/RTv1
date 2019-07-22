/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <cfahey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:19:52 by cfahey            #+#    #+#             */
/*   Updated: 2018/12/03 21:19:47 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	result = f(lst);
	head = result;
	lst = lst->next;
	while (lst)
	{
		if (!(result->next = f(lst)))
		{
			while (head->next)
			{
				result = head->next;
				free(head);
				head = result;
			}
		}
		lst = lst->next;
		result = result->next;
	}
	return (head);
}
