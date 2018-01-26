/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:16:47 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/20 10:16:49 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ptr;
	t_list *start;

	start = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	ptr = f(lst);
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	lst = lst->next;
	while (lst != NULL)
	{
		ptr->next = f(lst);
		if (ptr == NULL)
			return (NULL);
		lst = lst->next;
		ptr = ptr->next;
	}
	return (start);
}
