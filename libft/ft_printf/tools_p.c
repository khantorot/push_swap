/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 16:16:38 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:29:39 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*get_p(unsigned long long i)
{
	unsigned long long	l;
	unsigned long long	k;
	unsigned long long	b;
	int					j;
	char				*str;

	str = ft_strnew(30);
	b = 0;
	l = 0;
	k = i;
	if (k == 16)
		write(1, "0", 1);
	if (k < 16)
		ft_putchar(symbol_type_x(k));
	while (k > 16)
	{
		k = i;
		i = i / 16;
		j = k - i * 16;
		str[l] = symbol_type_x(j);
		l++;
	}
	str = ft_strrev(str);
	return (str);
}

void		print_p_sequel(t_pf *data, unsigned long long type)
{
	char				*tmp;
	char				*tmp2;

	tmp2 = get_p(type);
	if (tmp2[0] == '0')
		tmp = "0x1";
	else
		tmp = "0x";
	while ((size_t)data->precision > ft_strlen(tmp2))
	{
		tmp = ft_strjoin(tmp, "0");
		data->precision--;
	}
	data->data = ft_strjoin(tmp, tmp2);
	free(tmp2);
}

void		print_p_s(t_pf *data)
{
	data->len = ft_strlen(data->data);
	data->result += ft_strlen(data->data);
	if (data->minus == 1)
		print_minus_s(data);
	else
		print_s(data);
}
