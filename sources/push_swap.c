/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:37:48 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 16:17:08 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int		main(int argc, char **argv)
{
	t_data	data;

	data.mode = push_swap;
	init_data(&data);
	if (argc < 2)
		exit_free(&data);
	parse_data(&data, argc, argv);
	sort(&data);
	clean(&data);
	return (0);
}
