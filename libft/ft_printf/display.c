/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:53:47 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:28:14 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display(t_pf *data, char *str, va_list list)
{
	if (str[data->k] == '%')
		display_percent(data);
	else if (str[data->k] == 'd' || str[data->k] == 'i')
		display_int(str, list, data);
	else if (str[data->k] == 'o')
		display_o(str, list, data);
	else if (str[data->k] == 'u')
		display_u(str, list, data);
	else if (str[data->k] == 'x')
		display_x(str, list, data);
	else if (str[data->k] == 'X')
		display_capital_x(str, list, data);
	else if (str[data->k] == 'c')
		display_c(list, data);
	else if (str[data->k] == 's')
		display_s(list, data);
	else if (str[data->k] == 'p')
		display_p(list, data);
	else if (str[data->k] == 'f')
		display_f(str, list, data);
	else if (str[data->k] == '\0')
		return ;
}
