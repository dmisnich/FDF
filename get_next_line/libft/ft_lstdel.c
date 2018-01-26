/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:05:59 by dmisnich          #+#    #+#             */
/*   Updated: 2017/11/18 17:06:00 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst != NULL && del != NULL)
	{
		while (*alst != NULL)
		{
			temp = *alst;
			*alst = (*alst)->next;
			del(temp->content, temp->content_size);
		}
		free(temp);
		*alst = NULL;
	}
}
