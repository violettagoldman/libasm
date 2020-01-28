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

int		cmp(int a, int b)
{
	return (a > b);
}

int		cmp2(int a, int b)
{
	ft_printf("MUUR\n");
	return (a != b);
}

void	free_fct(void *el)
{
	(void)el;
	ft_printf("MEOW");
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

int		main(void)
{
	t_list *node;

	node = NULL;
	ft_printf("\033[0;33mft_atoi_base \033[0m\n");
	ft_printf("42 in 10: %d\n", ft_atoi_base("42", "0123456789"));
	ft_printf("-++++-++-42 in 10: %d\n", ft_atoi_base("-++++-++-42", "0123456789"));
	ft_printf("42 in 1: %d\n", ft_atoi_base("42", ""));
	ft_printf("0 in 10: %d\n", ft_atoi_base("0", "0123456789"));
	ft_printf("2A in 16: %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
	//ft_printf("42 in ' +012345': %d\n", ft_atoi_base("42", " +012345"));
	ft_printf("101010 in 2: %d\n", ft_atoi_base("101010", "01"));
	//ft_printf("42 in '\t0123456789': %d\n", ft_atoi_base("42", "\t0123456789"));
	ft_printf("   +-42 in 10: %d\n", ft_atoi_base("  +-42", "0123456789"));
	//ft_printf("--42 in 10: %d\n", ft_atoi_base("--42", "0123456789ABCDEF"));

	ft_printf("\033[0;33mft_list_push_front\n\033[0m");
	ft_list_push_front(&node, (void *)1);
	ft_list_push_front(&node, (void *)2);
	ft_list_push_front(&node, (void *)3);
	ft_list_push_front(&node, (void *)4);
	ft_list_push_front(&node, (void *)6);
	ft_list_push_front(&node, (void *)5);
	ft_list_print(node);
	
	ft_printf("\033[0;33mft_list_size \033[0m\n");
	ft_printf("Size of the list: %d\n", ft_list_size(node));

	ft_printf("\033[0;33mft_list_sort \033[0m\n");
	ft_list_sort(&node, &cmp);
	ft_list_print(node);

	ft_printf("\033[0;33mft_list_remove_if \033[0m\n");
	ft_printf("Remove: 3\n");
	//ft_list_remove_if(&node, (void *)1, &cmp2, &free_fct);
	ft_list_print(node);
	return (0);
}
