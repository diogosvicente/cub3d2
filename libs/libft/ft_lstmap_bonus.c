/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:20:07 by dioda-si          #+#    #+#             */
/*   Updated: 2022/11/26 10:45:05 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l1;
	t_list	*l2;

	if (lst == NULL)
		return (NULL);
	l1 = NULL;
	while (lst != NULL)
	{
		l2 = ft_lstnew((*f)(lst->content));
		if (l2 == NULL)
			ft_lstclear(&l2, (*del));
		else
			ft_lstadd_back(&l1, l2);
		lst = lst->next;
	}
	return (l1);
}
