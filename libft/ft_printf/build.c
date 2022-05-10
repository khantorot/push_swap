/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:43:37 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:25:44 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		build(char *str, t_pf *data, va_list list)
{
	while (str[data->i] != '\0')
	{
		data->i = parse_percent(str, data->i, data);
		data->k = parse_type(str, data->i);
		bundle(data, str);
		display(data, str, list);
		data->i = data->k + 1;
		if (str[data->k + 1] == '\0' || str[data->k] == '\0')
			return (data->result);
	}
	return (data->result);
}
