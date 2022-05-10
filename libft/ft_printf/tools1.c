/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:06:29 by glychest          #+#    #+#             */
/*   Updated: 2020/07/13 17:36:08 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*ft_itoa_unsinged(unsigned long long n)
{
	unsigned long long	tmpn;
	int					len;
	int					negative;
	char				*str;

	tmpn = n;
	len = 2;
	negative = 0;
	while (tmpn /= 10)
		len++;
	len += negative;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

unsigned long long		ft_squart(unsigned int i)
{
	unsigned long long	b;

	if (i == 0)
		return (1);
	b = 10;
	if (i > 1)
	{
		while (i != 1)
		{
			b = 10 * b;
			i--;
		}
	}
	return (b);
}

char					*ft_strrev(char *str)
{
	int		count;
	int		i;
	char	c;

	count = 0;
	while (str[count] != '\0')
		count++;
	count = count - 1;
	i = 0;
	while (i < ((count + 1) / 2))
	{
		c = str[i];
		str[i] = str[count - i];
		str[count - i] = c;
		i++;
	}
	return (str);
}

char					symbol_type_x(int i)
{
	char tmp;

	if (i < 10)
		tmp = i + '0';
	if (i == 10)
		tmp = 'a';
	if (i == 11)
		tmp = ('b');
	if (i == 12)
		tmp = ('c');
	if (i == 13)
		tmp = ('d');
	if (i == 14)
		tmp = ('e');
	if (i == 15)
		tmp = ('f');
	return (tmp);
}
