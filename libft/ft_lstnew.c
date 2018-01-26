/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:01:35 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/17 13:01:37 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (NULL);
	if (content == NULL)
	{
		head->content = NULL;
		head->content_size = 0;
		head->next = NULL;
	}
	else
	{
		head->content = (void *)malloc(content_size);
		if (head->content == NULL)
			return (NULL);
		ft_memcpy(head->content, (void *)content, content_size);
		head->content_size = content_size;
		head->next = NULL;
	}
	return (head);
}
