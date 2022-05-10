/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:24:33 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:28:33 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	parse_percent_alt(int k, t_pf *data)
{
	k = (k - 1) / 2;
	while (k > 0)
	{
		ft_putchar('%');
		data->result++;
		k--;
	}
}

static int	get_i(char *str, int i, t_pf *data)
{
	data->k = 1;
	while (str[i] != '%' && str[i])
	{
		ft_putchar(str[i]);
		i++;
		data->result++;
	}
	while (str[i] == '%' && str[i + 1] == '%' && str[i])
	{
		i++;
		data->k++;
	}
	return (i);
}

int			parse_percent(char *str, int i, t_pf *data)
{
	int k;

	i = get_i(str, i, data);
	k = data->k;
	if (k % 2 == 0)
	{
		k = k / 2;
		while (k > 0)
		{
			ft_putchar('%');
			data->result++;
			k--;
		}
		return (parse_percent(str, i + 1, data));
	}
	else
		parse_percent_alt(k, data);
	if (str[i] == '\0')
		return (i);
	return (i + 1);
}
