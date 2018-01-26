/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 11:11:35 by dmisnich          #+#    #+#             */
/*   Updated: 2018/01/26 10:50:49 by dmisnich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

t_gnl			*lst_new(void const *content, ssize_t size)
{
	t_gnl *head;

	head = (t_gnl *)malloc(sizeof(t_gnl));
	if (head == NULL)
		return (NULL);
	if (content == NULL)
	{
		head->str = NULL;
		head->fd = 0;
		head->next = NULL;
	}
	else
	{
		head->str = (void *)malloc(size);
		if (head->str == NULL)
			return (NULL);
		ft_memcpy(head->str, (void *)content, size);
		head->fd = size;
		head->next = NULL;
	}
	return (head);
}

static t_gnl	*sort_list(int fd, t_gnl **lst)
{
	t_gnl *head;

	head = *lst;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		head = head->next;
	}
	head = lst_new("", 1);
	head->next = *lst;
	*lst = head;
	(*lst)->fd = fd;
	return (*lst);
}

static int		search_and_read(int fd, t_gnl *lst, char **line, char *buf)
{
	ssize_t		ret;
	char		*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = lst->str;
		lst->str = ft_strjoin(lst->str, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (buf)
		free(buf);
	if (!ret && !ft_strlen(lst->str))
		return (0);
	*line = ft_strsub(lst->str, 0, ft_len(lst->str));
	tmp = lst->str;
	lst->str = ft_strsub(lst->str, ft_len(lst->str) + 1,
		ft_strlen(lst->str) - ft_strlen(*line));
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*file;
	char			*buf;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	file = sort_list(fd, &lst);
	return (search_and_read(fd, file, line, buf));
}
