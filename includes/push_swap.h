/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:37:28 by glychest          #+#    #+#             */
/*   Updated: 2020/11/03 13:45:10 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <stdbool.h>
# include <errno.h>
# include <limits.h>


# define SA		0
# define RA		1
# define RRA	2
# define SB		3
# define RB		4
# define RRB	5
# define SS		6
# define RR		7
# define RRR	8
# define PA		9
# define PB		10


typedef struct			s_lst
{
	int					n;
	struct s_lst		*next;
	struct s_lst		*prev;
}						t_lst;

typedef int				t_n;

typedef struct			s_chunk
{
	int					size;
	int					ipivot;
	t_n					pivot;
	struct s_chunk		*next;
}						t_chunk;

typedef struct			s_stack
{
	int					size;
	t_lst				*first;
	t_lst				*last;
	t_chunk				*top;
}						t_stack;

typedef enum			e_mode
{
	checker,
	push_swap,
}						t_mode;

typedef struct			s_data
{
	t_mode				mode;
	t_stack				a;
	t_stack				b;
	t_lst				**array;
	int					(*operator[11])(struct s_data*);
}						t_data;



void				exit_error(t_data *data);
void				exit_free(t_data *data);
void				clean(t_data *data);
void				init_data(t_data *data);
void				init_array(t_data *data);
void				parse_data(t_data *data, int argc, char **argv);
void				top_init(t_data *data);

void				operator_init(t_data *data);
void				swap(t_stack *data);
void				shift_up(t_stack *data);
void				shift_down(t_stack *data);
void				push(t_stack *dst, t_stack *src);
int					sa(t_data *data);
int					sb(t_data *data);
int					ss(t_data *data);
int					ra(t_data *data);
int					rb(t_data *data);
int					rr(t_data *data);
int					rra(t_data *data);
int					rrb(t_data *data);
int					rrr(t_data *data);
int					pa(t_data *data);
int					pb(t_data *data);

bool				correct_argv(char *argv, t_n *n);
bool				correct_argc(t_lst **array, int size);
t_n					strtonum(const char *str);
void				sort(t_data *data);
bool				is_sorted(t_data *data);
void				chunk_push(t_data *data, t_stack *x);
void				chunk_pop(t_stack *x);
bool				chunk_a_sorted(t_data *data);
bool				chunk_b_sorted(t_data *data);
void				a_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array);
void				a_to_b(t_chunk *b_dst, t_chunk *a_src, t_lst **array);
void				b_to_a(t_chunk *a_dst, t_chunk *b_src, t_lst **array);
void				b_to_b(t_chunk *b_dst, t_chunk *b_src, t_lst **array);
void				a_partition(t_data *data);
void				b_partition(t_data *data);
void				unload_b(t_data *data);

# endif