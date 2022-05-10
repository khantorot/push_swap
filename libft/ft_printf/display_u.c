/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 13:58:10 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:27:58 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_minus_u(t_pf *data)
{
	get_precision(data);
	ft_putstr(data->data);
	get_width(data);
	data->result += ft_strlen(data->data);
}

void	print_u(t_pf *data)
{
	get_width(data);
	get_precision(data);
	ft_putstr(data->data);
	data->result += ft_strlen(data->data);
}

void	init_u(t_pf *data)
{
	data->len = ft_strlen(data->data);
	data->hash = 0;
	data->space = 0;
	data->plus = 0;
	data->difference = data->precision - data->len;
}

void	display_u(char *str, va_list list, t_pf *data)
{
	unsigned long long	type;

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
	if (data->precision == -1)
		data->data = ft_strnew(1);
	else
		data->data = ft_itoa_unsinged(type);
	init_u(data);
	if (data->minus == 1)
		print_minus_u(data);
	else
		print_u(data);
	free(data->data);
}
