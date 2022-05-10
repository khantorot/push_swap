/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:34:22 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:27:47 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_minus_s(t_pf *data)
{
	ft_putstr(data->data);
	print_width_c(data);
}

void	print_s(t_pf *data)
{
	if (data->width > data->len)
		print_width_c(data);
	ft_putstr(data->data);
}

void	display_s(va_list list, t_pf *data)
{
	char *type;

	type = va_arg(list, char *);
	if (type == NULL)
	{
		data->data = ft_strnew(7);
		data->data = ft_strcpy(data->data, "(null)");
	}
	else if (data->precision != -1)
	{
		data->data = ft_strnew(ft_strlen(type) + 1);
		if (!data->precision)
			data->data = ft_strcpy(data->data, type);
		else if (data->precision)
			ft_strncpy(data->data, type, data->precision);
	}
	else
		data->data = ft_strnew(1);
	data->len = ft_strlen(data->data);
	data->result += ft_strlen(data->data);
	if (data->minus == 1)
		print_minus_s(data);
	else
		print_s(data);
	free(data->data);
}
