/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_a_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:31:02 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:13:47 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int		roq_count(t_lst *t, t_n pivot, int size)
{
	int	i;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		if (t->n < pivot)
			k++;
		t = t->next;
	}
	return (k);
}

static void		a_par_rest(t_data *data, int j)
{
	int		k;

	chunk_push(data, &data->b);
	a_to_b(data->b.top, data->a.top, data->array);
	k = roq_count(data->a.first, data->a.top->pivot, data->a.top->size - j);
	while (k)
		if (data->a.first->n < data->a.top->pivot)
			k -= pb(data);
		else
			j += ra(data);
	while (j)
	{
		j -= rra(data);
		if (data->a.first->n < data->a.top->pivot)
			(void)pb(data);
	}
	a_to_a(data->a.top, data->b.top, data->array);
}

void			a_partition(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chunk_push(data, &data->b);
	a_to_b(data->b.top, data->a.top, data->array);
	while (i < data->b.top->size)
		if (data->a.first->n < data->a.top->pivot)
			i += pb(data);
		else
			j += ra(data);
	a_to_a(data->a.top, data->b.top, data->array);
	if (data->a.size != data->a.top->size)
	{
		if (data->a.top->size > 4 && j)
			a_par_rest(data, j);
		else
			while (j)
				j -= rra(data);
	}
}
