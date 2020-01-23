#include "libftprintf.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

void	ft_list_print(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("| %s | -> ", (char *)tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL");
}

int		main(void)
{
	ft_printf("\033[0;33mft_atoi_base \033[0m");
	ft_printf("\033[0;33mft_list_push_front \033[0m");
	ft_printf("\033[0;33mft_list_size \033[0m");
	ft_printf("\033[0;33mft_sort \033[0m");
	ft_printf("\033[0;33mft_list_remove_if \033[0m");
	return (0);
}
