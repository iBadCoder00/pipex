/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavila- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:16:20 by adavila-          #+#    #+#             */
/*   Updated: 2024/02/12 16:17:23 by adavila-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*m_lst;

	if (!lst || !f || !del)
		return (0);
	head = 0;
	while (lst)
	{
		m_lst = ft_lstnew(f(lst->content));
		if (!m_lst)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, m_lst);
		lst = lst->next;
	}
	return (head);
}
