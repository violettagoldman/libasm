/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 09:59:31 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/04 13:39:37 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H
# include "libftprintf.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int		ft_strlen(const char *s);
char	*ft_strcpy(const char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, size_t nbyte);
int		ft_read(int fildes, const void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);
int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void	(*free_fct)(void *));
void	free_fct(void *el);
void	delete_list(t_list *list);
int		cmp(int a, int b);
int		cmp2(int a, int b);
void	ft_list_print(t_list *list);

#endif
