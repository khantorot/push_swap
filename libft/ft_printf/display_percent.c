/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:57:54 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:27:37 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	percent_width(t_pf *data)
{
	if (data->minus == 1)
		write(1, "%", 1);
	while (data->width >= 2)
	{
		write(1, " ", 1);
		data->result++;
		data->width--;
	}
	if (data->minus != 1)
		write(1, "%", 1);
	data->result++;
}

int			display_percent(t_pf *data)
{
	data->len = 0;
	percent_width(data);
	return (0);
}
