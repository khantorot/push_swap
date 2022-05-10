/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:29:01 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:29:04 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					get_f_len(long double type)
{
	int i;

	i = 0;
	while (type > 1)
	{
		type /= 10;
		i++;
	}
	return (i);
}

void				print_width_f(t_pf *data)
{
	while (data->len < data->width)
	{
		if (data->zero == 1 && data->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		data->width--;
		data->result++;
	}
}

static __int128_t	ft_atoi_f(char *str)
{
	__int128_t	res;
	__int128_t	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

static void			f_precision(long double tmp, t_pf *data)
{
	__int128_t	tmp2;

	while (data->precision >= 1)
	{
		tmp *= 10;
		tmp2 = tmp;
		ft_putchar(tmp + '0');
		tmp -= tmp2;
		data->precision--;
		data->result++;
	}
}

void				ft_putnbr_f(long double type, t_pf *data)
{
	long double	tmp;
	__int128_t	tmp2;
	int			start;
	char		*str;

	tmp = type;
	start = 0;
	str = ft_strnew(25);
	while (tmp > 1)
		tmp /= 10;
	while (data->len >= 2)
	{
		tmp *= 10;
		if (start != 0)
			tmp -= tmp2 * 10;
		tmp2 = tmp;
		ft_putchar(tmp2 + '0');
		str[start] = tmp + '0';
		data->len--;
		start++;
	}
	write(1, ".", 1);
	tmp = type - ft_atoi_f(str);
	free(str);
	f_precision(tmp, data);
}
