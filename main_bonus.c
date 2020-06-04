/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:03:59 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/04 20:30:27 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	atoi_base_test(void)
{
	ft_printf("\033[0;33mft_atoi_base \033[0m\n");
	ft_printf("NULL in NULL: %d\n", ft_atoi_base(NULL, NULL));
	ft_printf("101010 in 011: %d\n", ft_atoi_base("101010", "011"));
	ft_printf("42 in 01: %d\n", ft_atoi_base("42", "01"));
	ft_printf("42 in 0123456789: %d\n", ft_atoi_base("42", "0123456789"));
	ft_printf("-++++-++-42 in 10: %d\n",
		ft_atoi_base("-++++-++-42", "0123456789"));
	ft_printf("42 in 1: %d\n", ft_atoi_base("42", "1"));
	ft_printf("42 in '': %d\n", ft_atoi_base("42", ""));
	ft_printf("0 in 0123456789: %d\n", ft_atoi_base("0", "0123456789"));
	ft_printf("2A in 0123456789ABCDEF: %d\n",
		ft_atoi_base("2A", "0123456789ABCDEF"));
	ft_printf("101010 in 01: %d\n", ft_atoi_base("101010", "01"));
	ft_printf("   +-42 in 0123456789: %d\n",
		ft_atoi_base("  +-42", "0123456789"));
	ft_printf("700chmod in 0123456789: %d\n",
		ft_atoi_base("700chmod", "0123456789"));
}

void	list_push_front_test(t_list **node)
{
	ft_printf("\033[0;33mft_list_push_front\n\033[0m");
	ft_list_push_front(NULL, (void *)42);
	ft_list_push_front(node, (void *)1);
	ft_list_push_front(node, (void *)2);
	ft_list_push_front(node, (void *)3);
	ft_list_push_front(node, (void *)4);
	ft_list_push_front(node, (void *)6);
	ft_list_push_front(node, (void *)5);
	ft_list_print(*node);
}

int		main(void)
{
	t_list *node;

	node = NULL;
	atoi_base_test();
	list_push_front_test(&node);
	ft_printf("\033[0;33mft_list_size \033[0m\n");
	ft_printf("Size of the list: %d\n", ft_list_size(node));
	ft_printf("\033[0;33mft_list_sort \033[0m\n");
	ft_list_sort(&node, &cmp);
	ft_list_sort(NULL, &cmp);
	ft_list_print(node);
	ft_printf("\033[0;33mft_list_remove_if \033[0m\n");
	ft_printf("Remove: 3\n");
	ft_list_remove_if(&node, (void *)3, &cmp2, &free_fct);
	ft_list_remove_if(NULL, (void *)3, &cmp2, &free_fct);
	ft_list_print(node);
	delete_list(node);
	return (0);
}
