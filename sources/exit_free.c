/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:19:27 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 15:51:17 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	stack_clean(t_stack *x)
{
	while (x->first)
	{
		x->last = x->first;
		x->first = x->first->next;
		free(x->last);
	}
	while (x->top)
		chunk_pop(x);
}

void		clean(t_data *data)
{
	stack_clean(&data->a);
	stack_clean(&data->b);
	if (data->array)
		free(data->array);
}

void		exit_error(t_data *data)
{
	ft_printf("Error\n");
	clean(data);
	exit(8);
}

void		exit_free(t_data *data)
{
	clean(data);
	exit(0);
}