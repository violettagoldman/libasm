/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 09:54:09 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/04 13:26:46 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

int		cmp(int a, int b)
{
	return (a > b);
}

int		cmp2(int a, int b)
{
	return (a != b);
}

void	free_fct(void *el)
{
	(void)el;
}

void	ft_list_print(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("| %d | -> ", (int)tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}

void	delete_list(t_list *list)
{
	t_list *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		tmp = NULL;
	}
	list = NULL;
}
