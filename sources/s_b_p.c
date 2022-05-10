/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_b_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:31:27 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:14:36 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	unload_b(t_data *data)
{
	while (data->b.top->size)
	{
		pa(data);
		data->b.top->size--;
	}
	chunk_pop(&data->b);
}

void	b_partition(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	b_to_a(data->a.top, data->b.top, data->array);
	while (i < data->a.top->size)
		if (data->b.first->n >= data->b.top->pivot)
			i += pa(data);
		else
			j += rb(data);
	if (data->b.top->next)
		while (j)
			j -= rrb(data);
	b_to_b(data->b.top, data->b.top, data->array);
}