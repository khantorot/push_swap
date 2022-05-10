/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:30:45 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:26:51 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_int_sequel(t_pf *data, long long type)
{
	if (data->plus == 1 && type >= 0 && data->zero != 1)
	{
		write(1, "+", 1);
		data->result++;
		data->len++;
	}
	else if (data->space == 1 && data->plus != 1 &&
	type >= 0 && data->width < data->len)
	{
		write(1, " ", 1);
		data->result++;
		data->len++;
	}
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
		data->result += ft_strlen(data->data);
	}
	if (data->precision == -1 && data->width == 0 && data->type != 0)
	{
		get_width(data);
		ft_putstr(data->data);
		data->result += ft_strlen(data->data);
	}
}

static void	print_int(t_pf *data, long long type)
{
	if (data->zero == 1 && data->plus == 1 && data->type >= 0)
	{
		write(1, "+", 1);
		data->result++;
	}
	if (data->width > data->precision && data->type < 0 && data->precision != 0
	&& data->zero != 1)
	{
		precision_width(data);
		return ;
	}
	if ((data->type < 0 && data->len > data->width) ||
	(data->type < 0 && data->zero == 1) || (data->type < 0 &&
	data->width < data->precision))
		reinit_type_int(data, type);
	get_spec_width(data, type);
	print_int_sequel(data, type);
}

static void	print_minus_int(t_pf *data)
{
	if (data->plus == 1 && ft_atoi(data->data) >= 0)
	{
		if (ft_atoi(data->data) >= 0)
			write(1, "+", 1);
		data->result++;
		data->len++;
	}
	else if (data->space == 1 && data->plus != 1 && ft_atoi(data->data) >= 0)
	{
		write(1, " ", 1);
		data->result++;
		data->len++;
	}
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
		data->result += ft_strlen(data->data);
	}
	get_width(data);
}

void		display_int(char *str, va_list list, t_pf *data)
{
	long long		type;

	if (revise_conversion(str, data->k) == 0)
		type = (int)va_arg(list, long long);
	else
	{
		if (change_type(str, data->k) == 1)
			type = (long int)va_arg(list, long long);
		else if (change_type(str, data->k) == 2)
			type = (signed char)va_arg(list, long long);
		else if (change_type(str, data->k) == 3)
			type = (short int)va_arg(list, long long);
		else
			type = (long long int)va_arg(list, long long);
	}
	data->type = type;
	init_int(data, type);
	if (data->minus == 1)
		print_minus_int(data);
	else
		print_int(data, type);
	free(data->data);
}
