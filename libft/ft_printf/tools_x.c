/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 15:14:17 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:29:51 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*x_str(unsigned long long i, char *str)
{
	int					l;
	unsigned long long	j;
	unsigned long long	k;

	l = 0;
	k = i;
	while (k >= 16)
	{
		k = i;
		i = i / 16;
		j = k - i * 16;
		str[l] = symbol_type_x(j);
		l++;
	}
	return (str);
}

char				*get_x(unsigned long long i)
{
	unsigned long long	l;
	unsigned long long	b;
	char				*str;

	str = ft_strnew(15);
	b = 0;
	l = 0;
	if (i == 16)
		write(1, "0", 1);
	if (i < 9)
		str[0] = i + '0';
	if (i < 16 && i > 10)
		str[0] = symbol_type_x(i);
	if (i > 16)
		str = x_str(i, str);
	str = ft_strrev(str);
	return (str);
}

unsigned long long	capital_x_type(va_list list, char *str, t_pf *data)
{
	unsigned long long type;

	if (change_type(str, data->k) == 1)
		type = (unsigned long int)va_arg(list, unsigned long long);
	else if (change_type(str, data->k) == 2)
		type = (unsigned char)va_arg(list, unsigned long long);
	else if (change_type(str, data->k) == 3)
		type = (unsigned short int)va_arg(list, unsigned long long);
	else
		type = (unsigned long long int)va_arg(list, unsigned long long);
	return (type);
}

static char			*get_capital(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'a')
			str[i] = ('A');
		else if (str[i] == 'b')
			str[i] = ('B');
		else if (str[i] == 'c')
			str[i] = ('C');
		else if (str[i] == 'd')
			str[i] = ('D');
		else if (str[i] == 'e')
			str[i] = ('E');
		else if (str[i] == 'f')
			str[i] = ('F');
		i++;
	}
	return (str);
}

void				capital_x(t_pf *data, long long type)
{
	data->data = get_x(type);
	data->data = get_capital(data->data);
}
