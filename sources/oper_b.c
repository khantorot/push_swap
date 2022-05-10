/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:25:36 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:11:00 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	sb(t_data *data)
{
	swap(&data->b);
	if (data->mode == push_swap)
		ft_putendl("sb");
	return (1);
}

int	rb(t_data *data)
{
	shift_up(&data->b);
	if (data->mode == push_swap)
		ft_putendl("rb");
	return (1);
}

int	rrb(t_data *data)
{
	shift_down(&data->b);
	if (data->mode == push_swap)
		ft_putendl("rrb");
	return (1);
}

int	pb(t_data *data)
{
	push(&data->b, &data->a);
	if (data->a.size)
	{
		data->b.size++;
		data->a.size--;
	}
	if (data->mode == push_swap)
		ft_putendl("pb");
	return (1);
}
