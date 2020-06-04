/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <vgoldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 13:51:03 by vgoldman          #+#    #+#             */
/*   Updated: 2020/06/04 22:35:19 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <string.h>
#include <errno.h>

void	ft_assert(int a, int b)
{
	if (a == b)
		ft_printf("\033[1;32m[OK]\033[0m");
	else
		ft_printf("\033[1;31m[FAIL]\033[0m");
}

void	strlen_test(void)
{
	ft_printf("\033[0;33mft_strlen ");
	ft_assert(ft_strlen("test"), 4);
	ft_assert(ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Integer accumsan nec urna sit amet efficitur. Sed sit amet pulvinar\
	erat, eu interdum velit. Aliquam erat volutpat. Integer nec velit purus.\
	Cras cursus, nibh vel consequat imperdiet, nisl urna venenatis est, nec\
	elementum lacus ligula vitae lectus. Nam massa urna, placerat a mauris\
	eget, gravida volutpat dui. Sed faucibus felis et risus rhoncus, sit amet\
	suscipit magna varius. Donec at turpis mauris. Sed tincidunt, nisl vitae\
	euismod eleifend, magna urna viverra sapien, eget lacinia tortor velit non\
	sapien. Nulla orci risus, eleifend eu interdum at, malesuada in lacus.\
	Aenean consequat facilisis diam a porttitor."), 678);
	ft_assert(ft_strlen(""), 0);
	ft_assert(ft_strlen("\0FAIL"), 0);
}

void	read_write_test(void)
{
	int		i;
	char	*buffer;
	int		res;

	i = 0;
	if (!(buffer = (char *)malloc(sizeof(char) * 256000)))
		return ;
	while (i < 256000)
	{
		buffer[i] = 0;
		i++;
	}
	ft_printf("\n\033[0;33mft_read errno \033[0m");
	res = ft_read(3, buffer, 10);
	ft_printf("%d, %s, %d\n", errno, strerror(errno), res);
	ft_printf("\033[0;33mft_read \033[0m");
	res = ft_read(0, buffer, 256000);
	ft_printf("%d, %s, %d\n", errno, strerror(errno), res);
	ft_printf("\033[0;33mft_write \033[0m");
	res = ft_write(1, buffer, 256000);
	ft_printf("%d, %s, %d", errno, strerror(errno), res);
	ft_printf("\n\033[0;33mft_write errno \033[0m");
	res = ft_write(10, buffer, 1);
	ft_printf("%d, %s, %d", errno, strerror(errno), res);
	free(buffer);
	buffer = NULL;
}

int		main(void)
{
	char		*src;
	char		*dst;
	char		*res;

	if (!(src = (char *)malloc(sizeof(char) * 100)))
		return (0);
	if (!(dst = (char *)malloc(sizeof(char) * 10)))
		return (0);
	strlen_test();
	ft_printf("\n\033[0;33mft_strcpy\033[0m ");
	ft_strcpy(src, "test");
	ft_strcpy(dst, src);
	ft_printf("Src: %s Dst: %s", src, dst);
	free(dst);
	dst = NULL;
	ft_printf("\n\033[0;33mft_strdup \033[0m");
	res = ft_strdup(src);
	ft_printf("Src: %s Res: %s", src, res);
	free(res);
	res = NULL;
	free(src);
	read_write_test();
	return (0);
}
