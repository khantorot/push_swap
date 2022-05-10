/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:39:31 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:29:18 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_int(t_pf *data, long long type)
{
	if (type == -9223372036854775806 - 2)
	{
		data->data = ft_strnew(21);
		data->data = ft_strcpy(data->data, "-9223372036854775808");
	}
	else
		data->data = ft_itoa(type);
	data->len = ft_strlen(data->data);
	if (data->precision == -1)
		data->len = 0;
	data->hash = 0;
	data->difference = data->precision - data->len;
}

void		precision_width(t_pf *data)
{
	if (data->precision > data->len)
		data->width--;
	get_width(data);
	write(1, "-", 1);
	data->result++;
	free(data->data);
	data->type *= -1;
	data->data = ft_itoa(data->type);
	get_precision(data);
	ft_putstr(data->data);
	data->result += ft_strlen(data->data);
}

void		reinit_type_int(t_pf *data, long long type)
{
	write(1, "-", 1);
	data->result++;
	free(data->data);
	data->type *= -1;
	data->data = ft_itoa(data->type);
	if (type == -9223372036854775806 - 2)
	{
		data->data = ft_strnew(20);
		data->data = ft_strcpy(data->data, "9223372036854775808");
	}
}

static void	fill_spec(t_pf *data, long long type)
{
	if (data->plus == 1 && type >= 0)
		data->width--;
	if (data->space == 1 && data->zero == 1)
	{
		write(1, " ", 1);
		data->width--;
		data->result++;
	}
}

void		get_spec_width(t_pf *data, long long type)
{
	fill_spec(data, type);
	if (data->len > data->precision)
	{
		while (data->width > data->len)
		{
			if (data->zero == 1 && !data->precision && data->minus != 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			data->width--;
			data->result++;
		}
	}
	else if (data->precision > data->len)
		while (data->width > data->precision)
		{
			if (data->zero == 1 && !data->precision && data->minus != 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			data->width--;
			data->result++;
		}
}
