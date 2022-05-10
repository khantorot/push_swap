/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:36:30 by glychest          #+#    #+#             */
/*   Updated: 2020/10/30 13:25:37 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_pf
{
	char			*data;
	long long		type;
	int				result;
	int				i;
	int				k;
	int				k2;
	int				len;
	int				width;
	int				minus;
	int				plus;
	int				hash;
	int				zero;
	int				space;
	int				precision;
	int				difference;
}					t_pf;

int					ft_printf(const char *format, ...);
void				init(t_pf *data);
int					build(char *str, t_pf *data, va_list list);
void				bundle(t_pf *data, char *str);
void				display(t_pf *data, char *str, va_list list);

int					parse_percent(char *str, int i, t_pf *data);
int					parse_type(char *str, int i);
int					parse_width(char *str, int i, int k);
int					parse_precision(char *str, int k);
int					parse_hashtag_flag(char *str, int i);
int					parse_space_flag(char *str, int i);
int					parse_zero_flag(char *str, int i);
int					parse_plus_flag(char *str, int i);
int					parse_minus_flags(char *str, int i);

int					display_percent(t_pf *data);
void				display_int(char *str, va_list list, t_pf *data);
void				init_int(t_pf *data, long long type);
void				reinit_type_int(t_pf *data, long long type);
void				precision_width(t_pf *data);
void				get_spec_width(t_pf *data, long long type);
void				display_o(char *str, va_list list, t_pf *data);
void				init_o(t_pf *data);
long long			get_o_type(t_pf *data, char *str, va_list list);
void				reinit_type_o(unsigned long long i, t_pf *data);
void				display_u(char *str, va_list list, t_pf *data);
void				display_x(char *str, va_list list, t_pf *data);
char				*get_x(unsigned long long i);
void				display_capital_x(char *str, va_list list, t_pf *data);
unsigned long long	capital_x_type(va_list list, char *str, t_pf *data);
void				capital_x(t_pf *data, long long type);
void				display_c(va_list list, t_pf *data);
void				print_width_c(t_pf *data);
void				display_s(va_list list, t_pf *data);
void				print_s(t_pf *data);
void				print_minus_s(t_pf *data);
void				display_p(va_list list, t_pf *data);
void				print_p_sequel(t_pf *data, unsigned long long type);
void				print_p_s(t_pf *data);
void				display_f(char *str, va_list list, t_pf *data);
void				print_width_f(t_pf *data);
void				ft_putnbr_f(long double type, t_pf *data);
int					get_f_len(long double type);

int					revise_conversion(char *str, int k);
int					change_type(char *str, int k);
void				get_width(t_pf *data);
void				get_precision(t_pf *data);
char				symbol_type_x(int i);
char				*ft_itoa_unsinged(unsigned long long n);
void				ft_putnbr_u(unsigned long long n);
char				*ft_strrev(char *str);

#endif
