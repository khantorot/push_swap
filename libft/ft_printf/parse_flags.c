/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:29:29 by glychest          #+#    #+#             */
/*   Updated: 2020/07/13 11:52:02 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		parse_hashtag_flag(char *str, int i)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
	|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int		parse_space_flag(char *str, int i)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
	|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		parse_zero_flag(char *str, int i)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
	|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int		parse_plus_flag(char *str, int i)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
	|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '+')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		parse_minus_flags(char *str, int i)
{
	while (str[i] == '-' || str[i] == '+' || str[i] == ' '
	|| str[i] == '#' || str[i] == '0')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}
