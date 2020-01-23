#include "libftprintf.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *));


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

int		main(void)
{
	t_list *node;

	node = NULL;
	/*
	ft_printf("\033[0;33mft_atoi_base \033[0m\n");
	ft_printf("42 in 10: %d\n", ft_atoi_base("42", "0123456789"));
	ft_printf("42 in 1: %d\n", ft_atoi_base("42", "1"));
	ft_printf("0 in 10: %d\n", ft_atoi_base("42", "0123456789"));
	ft_printf("42 in ' +012345': %d\n", ft_atoi_base("42", " +012345"));
	ft_printf("42 in 2: %d\n", ft_atoi_base("42", "01"));
	ft_printf("42 in '\t0123456789': %d\n", ft_atoi_base("42", "\t0123456789"));
	ft_printf("  +-42 in 10: %d\n", ft_atoi_base("  +-42", "0123456789"));
	ft_printf("--42 in 10: %d\n", ft_atoi_base("--42", "0123456789ABCDEF"));*/
	
	ft_printf("\033[0;3f3mft_list_push_front \033[0m\n");
	/*ft_list_push_front(&node, 1);
	ft_list_push_front(&node, 2);
	ft_list_push_front(&node, 3);
	ft_list_push_front(&node, 4);
	ft_list_push_front(&node, 6);
	ft_list_push_front(&node, 5);
	ft_list_print(node);*/
	
	ft_printf("\033[0;33mft_list_size \033[0m\n");
	//ft_printf("Size of the list: %d\n", ft_list_size(node));

	ft_printf("\033[0;33mft_list_sort \033[0m\n");
	/*ft_list_sort(node);
	ft_list_push(node);*/

	ft_printf("\033[0;33mft_list_remove_if \033[0m\n");
	
	return (0);
}
