/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:25:24 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:10:19 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->mode == push_swap)
		ft_putendl("ss");
	return (1);
}

int	rr(t_data *data)
{
	shift_up(&data->a);
	shift_up(&data->b);
	if (data->mode == push_swap)
		ft_putendl("rr");
	return (1);
}

int	rrr(t_data *data)
{
	shift_down(&data->a);
	shift_down(&data->b);
	if (data->mode == push_swap)
		ft_putendl("rrr");
	return (1);
}
