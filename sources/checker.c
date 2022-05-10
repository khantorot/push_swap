/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:37:52 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 17:06:28 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_operations(char *line)
{
	if (ft_strequ(line, "sa"))
		return (SA);
	else if (ft_strequ(line, "ra"))
		return (RA);
	else if (ft_strequ(line, "rra"))
		return (RRA);
	else if (ft_strequ(line, "sb"))
		return (SB);
	else if (ft_strequ(line, "rb"))
		return (RB);
	else if (ft_strequ(line, "rrb"))
		return (RRB);
	else if (ft_strequ(line, "ss"))
		return (SS);
	else if (ft_strequ(line, "rr"))
		return (RR);
	else if (ft_strequ(line, "rrr"))
		return (RRR);
	else if (ft_strequ(line, "pa"))
		return (PA);
	else if (ft_strequ(line, "pb"))
		return (PB);
	else
		return (-1);
}

void	get_operations(t_data *data)
{
	char	*line;
	int		i;

	while (get_next_line(STDIN_FILENO, &line))
	{
		if ((i = check_operations(line)) < 0)
			exit_error(data);
		data->operator[i](data);
		free(line);
	}
}

int 	main(int argc, char **argv)
{
	t_data data;

	data.mode = checker;
	init_data(&data);
	if (argc < 2)
		exit_free(&data);
	parse_data(&data, argc, argv);
	get_operations(&data);
	if (is_sorted(&data))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	clean(&data);
	return (0);
}
