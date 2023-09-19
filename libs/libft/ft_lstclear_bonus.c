/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dioda-si <dioda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:54:19 by dioda-si          #+#    #+#             */
/*   Updated: 2022/11/26 12:02:22 by dioda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			ft_lstdelone(*lst, del);
			*lst = (*lst)->next;
		}
		*lst = NULL;
	}
}
