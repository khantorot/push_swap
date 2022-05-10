/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:20:07 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 17:33:45 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	lst_push(t_data *data, t_n n)
{
	t_lst	*new;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		exit_error(data);
	new->n = n;
	new->prev = data->a.last;
	new->next = NULL;
	if (data->a.last)
		data->a.last->next = new;
	if (!data->a.first)
		data->a.first = new;
	data->a.last = new;
}

static void	parsing(t_data *data, char *argv)
{
	char	**s;
	int		i;
	t_n		n;

	s = ft_strsplit((const char*)argv, ' ');
	i = 0;
	while (s[i])
	{
		if (!correct_argv(s[i], &n))
			exit_error(data);
		lst_push(data, n);
		data->a.size++;
		free(s[i]);
		i++;
	}
	free(s);
}

void		parse_data(t_data *data, int argc, char **argv)
{
	while (--argc)
	{
		if (!*++argv)
			continue ;
		parsing(data, *argv);
	}
	if (!(data->array = (t_lst**)malloc(sizeof(t_lst*) * data->a.size)))
		exit_error(data);
	init_array(data);
	if (!correct_argc(data->array, data->a.size))
		exit_error(data);
	top_init(data);
	operator_init(data);
}
