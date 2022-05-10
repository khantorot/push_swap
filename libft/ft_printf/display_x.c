/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:36:23 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:28:09 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_minus_x(t_pf *data)
{
	if (data->hash == 1)
		ft_putstr("0x");
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	get_width(data);
	data->result += ft_strlen(data->data);
}

static void	print_x(t_pf *data)
{
	if (data->zero == 1 && data->hash == 1 && ft_atoi(data->data) != 0)
		ft_putstr("0x");
	get_width(data);
	if (data->hash == 1 && data->zero == 0 && ft_atoi(data->data) != 0)
		ft_putstr("0x");
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	data->result += ft_strlen(data->data);
}

static void	init_x(t_pf *data)
{
	data->len = ft_strlen(data->data);
	data->difference = data->precision - data->len;
	if (data->hash == 1 && ft_atoi(data->data) != 0)
	{
		data->len += 2;
		data->result += 2;
	}
}

void		display_x(char *str, va_list list, t_pf *data)
{
	unsigned long long		type;

	if (revise_conversion(str, data->k) == 0)
		type = (unsigned int)va_arg(list, unsigned long long);
	else
	{
		if (change_type(str, data->k) == 1)
			type = (unsigned long int)va_arg(list, unsigned long long);
		else if (change_type(str, data->k) == 2)
			type = (unsigned char)va_arg(list, unsigned long long);
		else if (change_type(str, data->k) == 3)
			type = (unsigned short int)va_arg(list, unsigned long long);
		else if (change_type(str, data->k) == 4)
			type = (unsigned long long int)va_arg(list, unsigned long long);
	}
	if (data->precision != -1)
		data->data = get_x(type);
	else
		data->data = ft_strnew(1);
	init_x(data);
	if (data->minus == 1)
		print_minus_x(data);
	if (data->minus != 1)
		print_x(data);
	free(data->data);
}
