/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:32:44 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 17:13:17 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	sort(t_data *data)
{
	while (!is_sorted(data))
	{
		while (data->a.top->size)
			if (chunk_a_sorted(data))
				data->a.top->size = 0;
			else if (data->a.top->size == 2)
			{
				(void)sa(data);
				data->a.top->size = 0;
			}
			else
				a_partition(data);
		data->a.top->size = 0;
		if (data->b.top->size != 0)
		{
			if (chunk_b_sorted(data))
				unload_b(data);
			else if (data->b.top->size == 2)
			{
				(void)sb(data);
				unload_b(data);
			}
			else
				b_partition(data);
		}
	}
}