/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:26:14 by bchedru           #+#    #+#             */
/*   Updated: 2023/10/27 18:02:41 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*temp;

	res = NULL;
	while (list)
	{
		temp = ft_lstnew(NULL);
		if (!temp)
		{
			ft_lstclear(&res, del);
			break ;
		}
		temp->content = f(list->content);
		ft_lstadd_back(&res, temp);
		list = list->next;
	}
	return (res);
}
