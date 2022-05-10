/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:34:45 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:30:03 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			revise_conversion(char *str, int k)
{
	int res;

	res = 0;
	k = k - 1;
	if (str[k] == 'l' || str[k] == 'h')
		res = 1;
	return (res);
}

int			change_type(char *str, int k)
{
	k = k - 1;
	while (str[k] == 'h' || str[k] == 'l' || str[k] == 'L')
	{
		if (str[k] == 'l' && str[k - 1] != 'l')
			return (1);
		else if (str[k] == 'h' && str[k - 1] == 'h')
			return (2);
		else if (str[k] == 'h' && str[k - 1] != 'h')
			return (3);
		else if (str[k] == 'l' && str[k - 1] == 'l')
			return (4);
		else if (str[k] == 'L')
			return (5);
	}
	return (0);
}

static void	check_width(t_pf *data)
{
	if (data->plus == 1 && data->type >= 0)
		data->width--;
}

void		get_width(t_pf *data)
{
	check_width(data);
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
	{
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
}

void		get_precision(t_pf *data)
{
	int i;

	i = ft_strlen(data->data);
	if (data->precision > data->len)
		data->len += data->precision - data->len;
	while (data->precision > i)
	{
		write(1, "0", 1);
		data->precision--;
		data->result++;
	}
}
