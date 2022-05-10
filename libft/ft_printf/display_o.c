/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:32:12 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:27:15 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_minus_o(t_pf *data)
{
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	if (data->hash == 1 && data->precision == -1)
	{
		write(1, "0", 1);
		data->result++;
	}
	get_width(data);
	data->result += ft_strlen(data->data);
}

static void	print_o(t_pf *data)
{
	get_width(data);
	if (data->hash == 1 && data->precision == -1)
	{
		ft_putstr(data->data);
		data->result += data->len;
		return ;
	}
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	data->result += ft_strlen(data->data);
}

void		display_o(char *str, va_list list, t_pf *data)
{
	unsigned long long		type;

	if (revise_conversion(str, data->k) == 0)
		type = (unsigned int)va_arg(list, unsigned long long);
	else
		type = get_o_type(data, str, list);
	data->type = type;
	if (data->precision != -1 || data->hash == 1)
		reinit_type_o(type, data);
	else
		data->data = ft_strnew(1);
	init_o(data);
	if (data->minus == 1)
		print_minus_o(data);
	else
		print_o(data);
	free(data->data);
}
