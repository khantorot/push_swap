/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:40:46 by glychest          #+#    #+#             */
/*   Updated: 2020/11/04 13:16:16 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void		init_data(t_data *data)
{
	data->a.first = NULL;
	data->a.last = NULL;
	data->a.top = NULL;
	data->a.size = 0;
	data->b.first = NULL;
	data->b.last = NULL;
	data->b.top = NULL;
	data->b.size = 0;
	data->array = NULL;
}



void		operator_init(t_data *data)
{
	data->operator[SA] = sa;
	data->operator[RA] = ra;
	data->operator[RRA] = rra;
	data->operator[SB] = sb;
	data->operator[RB] = rb;
	data->operator[RRB] = rrb;
	data->operator[SS] = ss;
	data->operator[RR] = rr;
	data->operator[RRR] = rrr;
	data->operator[PA] = pa;
	data->operator[PB] = pb;
}

void				top_init(t_data *data)
{
	chunk_push(data, &data->a);
	chunk_push(data, &data->b);
	data->a.top->size = data->a.size;
	data->a.top->ipivot = data->a.top->size / 2;
	data->a.top->pivot = data->array[data->a.top->ipivot]->n;
	data->b.top->size = 0;
}

static void			array_sort(t_lst **array, int size)
{
	int		i;
	int		j;
	int		sorted;
	t_lst	*t;

	i = -1;
	sorted = 0;
	while (++i < size && !sorted)
	{
		j = 0;
		sorted = 1;
		while (++j < size - i)
			if (array[j]->n < array[j - 1]->n)
			{
				t = array[j];
				array[j] = array[j - 1];
				array[j - 1] = t;
				sorted = 0;
			}
	}
}

void				init_array(t_data *data)
{
	t_lst	*t;
	int		i;

	i = 0;
	t = data->a.first;
	while (t)
	{
		data->array[i] = t;
		t = t->next;
		i++;
	}
	array_sort(data->array, data->a.size);
}