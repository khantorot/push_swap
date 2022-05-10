/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_capital_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:36:47 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:26:09 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_minus_xx(t_pf *data)
{
	if (data->hash == 1)
		ft_putstr("0X");
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	get_width(data);
	data->result += ft_strlen(data->data);
}

static void	print_xx(t_pf *data)
{
	if (data->zero == 1 && data->hash == 1)
		ft_putstr("0X");
	get_width(data);
	if (data->hash == 1 && data->zero == 0)
		ft_putstr("0X");
	if (data->precision != -1)
	{
		get_precision(data);
		ft_putstr(data->data);
	}
	data->result += ft_strlen(data->data);
}

static void	init_xx(t_pf *data)
{
	data->len = ft_strlen(data->data);
	data->difference = data->precision - data->len;
	if (data->hash == 1)
	{
		data->len += 2;
		data->result += 2;
	}
}

void		display_capital_x(char *str, va_list list, t_pf *data)
{
	unsigned long long		type;

	if (revise_conversion(str, data->k) == 0)
		type = (unsigned int)va_arg(list, unsigned long long);
	else
		type = capital_x_type(list, str, data);
	if (type == 0 && data->precision != -1)
	{
		write(1, "0", 1);
		data->result++;
		return ;
	}
	if (data->precision != -1)
		capital_x(data, type);
	else
		data->data = ft_strnew(1);
	init_xx(data);
	if (data->minus == 1)
		print_minus_xx(data);
	else
		print_xx(data);
	free(data->data);
}
