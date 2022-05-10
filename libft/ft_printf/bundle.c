/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bundle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:18:25 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:25:49 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	bundle(t_pf *data, char *str)
{
	data->width = parse_width(str, data->i, data->k);
	data->precision = parse_precision(str, data->k);
	data->minus = parse_minus_flags(str, data->i);
	data->plus = parse_plus_flag(str, data->i);
	data->hash = parse_hashtag_flag(str, data->i);
	data->zero = parse_zero_flag(str, data->i);
	data->space = parse_space_flag(str, data->i);
}
