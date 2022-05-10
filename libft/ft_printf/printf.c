/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:17:49 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:28:48 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		list;
	t_pf		*data;

	if (!(data = (t_pf *)ft_memalloc(sizeof(t_pf))))
		return (-1);
	init(data);
	va_start(list, format);
	data->result = build((char *)format, data, list);
	va_end(list);
	free(data);
	return (data->result);
}
