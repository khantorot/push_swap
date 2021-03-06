/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:18:17 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 16:18:35 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	a_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array)
{
	a_dst->size -= b_src->size;
	a_dst->ipivot += a_dst->size / 2;
	a_dst->pivot = array[a_dst->ipivot]->n;
}

void	a_to_b(t_chunk *b_dst, t_chunk *a_src, t_lst **array)
{
	b_dst->size = a_src->size / 2;
	b_dst->ipivot = a_src->ipivot - b_dst->size + b_dst->size / 2;
	b_dst->pivot = array[b_dst->ipivot]->n;
}

void	b_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array)
{
	a_dst->size = b_src->size - b_src->size / 2;
	a_dst->ipivot = b_src->ipivot + a_dst->size / 2;
	a_dst->pivot = array[a_dst->ipivot]->n;
}

void	b_to_b(t_chunk *b_dst, t_chunk *b_src, t_lst **array)
{
	b_dst->size = b_src->size / 2;
	b_dst->ipivot = b_src->ipivot - b_dst->size + b_dst->size / 2;
	b_dst->pivot = array[b_dst->ipivot]->n;
}