/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ut3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoldman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:09:31 by vgoldman          #+#    #+#             */
/*   Updated: 2019/11/26 10:10:35 by vgoldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		len_nb_hexa(long int n, t_format *format)
{
	int i;

	i = 0;
	if (format->flags[4])
		i += 2;
	while (n >= 16)
	{
		n /= 16;
		i++;
	}
	return (i + 1);
}
