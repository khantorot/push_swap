/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:33:35 by glychest          #+#    #+#             */
/*   Updated: 2020/10/31 17:39:27 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

bool	correct_argv(char *argv, t_n *n)
{
	errno = 0;
	*n = strtonum((const char*)argv);
	if (errno == ERANGE || errno == EINVAL)
		return (false);
	return (true);
}

bool	correct_argc(t_lst **array, int size)
{
	int	i;

	i = 0;
	while (++i < size)
		if (array[i]->n == array[i - 1]->n)
			return (false);
	return (true);
}

bool		is_sorted(t_data *data)
{
	t_lst	*t;

	if ((t = data->a.first))
		while ((t = t->next))
			if (t->prev->n > t->n)
				return (false);
	return (!data->b.size);
}

t_n			strtonum(const char *str)
{
	__int128_t	f;
	__int128_t	r;
	int			sign;

	f = 0;
	r = (__int128_t)INT_MAX + 2;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (*str == '-' && (sign = -1)))
		str++;
	if (!ft_isdigit(*str))
		errno = EINVAL;
	while (ft_isdigit(*str) && f < r)
		f = (f << 3) + (f << 1) + *str++ + (~0x30 + 1);
	if (f >= r || (f == r - 1 && sign > 0))
		errno = ERANGE;
	while (ft_isdigit(*str))
		str++;
	if (!ft_isdigit(*str) && *str)
		errno = EINVAL;
	return (f * sign);
}
