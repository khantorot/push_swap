/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:18:53 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:08:32 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	chunk_push(t_data *data, t_stack *x)
{
	t_chunk	*new;

	if (!x->top || x->top->size)
	{
		if (!(new = (t_chunk*)malloc(sizeof(t_chunk))))
			exit_error(data);
		new->next = x->top;
		x->top = new;
	}
}

void	chunk_pop(t_stack *x)
{
	t_chunk	*t;

	if ((t = x->top))
	{
		x->top = x->top->next;
		free(t);
	}
}

bool	chunk_a_sorted(t_data *data)
{
	t_lst	*t;
	int		i;

	t = data->a.first->next;
	i = 0;
	while (++i < data->a.top->size)
	{
		if (t->prev->n > t->n)
			return (false);
		t = t->next;
	}
	return (true);
}

bool	chunk_b_sorted(t_data *data)
{
	t_lst	*t;
	int		i;

	t = data->b.first->next;
	i = 0;
	while (++i < data->b.top->size)
	{
		if (t->prev->n < t->n)
			return (false);
		t = t->next;
	}
	return (true);
}
