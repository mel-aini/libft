/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-aini <mel-aini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:03:25 by mel-aini          #+#    #+#             */
/*   Updated: 2022/10/27 12:12:09 by mel-aini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	tmp = head;
	if (!tmp)
	{
		del(tmp->content);
		free(tmp);
		return (NULL);
	}
	while (lst->next != NULL)
	{
		new = ft_lstnew(f(lst->content));
		tmp->next = new;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
