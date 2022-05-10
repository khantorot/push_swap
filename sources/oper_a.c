/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:25:03 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:09:49 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	sa(t_data *data)
{
	swap(&data->a);
	if (data->mode == push_swap)
		ft_putendl("sa");
	return (1);
}

int	ra(t_data *data)
{
	shift_up(&data->a);
	if (data->mode == push_swap)
		ft_putendl("ra");
	return (1);
}

int	rra(t_data *data)
{
	shift_down(&data->a);
	if (data->mode == push_swap)
		ft_putendl("rra");
	return (1);
}

int	pa(t_data *data)
{
	push(&data->a, &data->b);
	if (data->b.size)
	{
		data->a.size++;
		data->b.size--;
	}
	if (data->mode == push_swap)
		ft_putendl("pa");
	return (1);
}
