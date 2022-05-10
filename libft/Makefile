# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glychest <glychest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 14:44:50 by glychest          #+#    #+#              #
#    Updated: 2020/10/29 17:50:55 by glychest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_CHAR_FOLDER =	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_isupper.c \
					ft_islower.c \
					ft_toupper.c \
					ft_tolower.c 

FT_LST_FOLDER = 	ft_lstnew.c \
					ft_lstdelone.c \
					ft_lstdel.c \
					ft_lstadd.c \
					ft_lstmap.c \
					ft_lstiter.c


FT_STR_FOLDER = 	ft_strcat.c \
					ft_strchr.c \
					ft_strclr.c \
					ft_strcmp.c \
					ft_strcpy.c \
					ft_strdel.c \
					ft_strdup.c \
					ft_strequ.c \
					ft_striter.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlen.c \
					ft_strmap.c \
					ft_strmapi.c \
					ft_strncat.c \
					ft_strncmp.c \
					ft_strncpy.c \
					ft_strndup.c \
					ft_strnequ.c \
					ft_strnew.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strsplit.c \
					ft_strstr.c \
					ft_strsub.c \
					ft_strtrim.c \

FT_MEM_FOLDER = 	ft_bzero.c \
					ft_memalloc.c \
					ft_memccpy.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memdel.c \
					ft_memmove.c \
					ft_memset.c

FT_PUT_FOLDER = 	ft_putchar_fd.c \
					ft_putchar.c \
					ft_putendl_fd.c \
					ft_putendl.c \
					ft_putnbr_fd.c \
					ft_putnbr.c \
					ft_putstr_fd.c \
					ft_putstr.c 
		
		

FT_LIB_FOLDER = 	ft_abs.c \
					ft_atoi_base.c \
					ft_atoi.c \
					ft_check.c \
					ft_error.c \
					ft_free_arr.c \
					ft_isnumber.c \
					ft_itoa_base.c \
					ft_itoa.c\
					ft_max.c\
					ft_min.c\
					ft_swap.c

GET_NEXT_LINE =  	get_next_line.c

FT_PRINTF_FOLDER =	build.c \
					bundle.c \
					display_c.c \
					display_capital_x.c \
					display_f.c \
					display_int.c \
					display_o.c \
					display_p.c \
					display_percent.c \
					display_s.c \
					display_u.c \
					display_x.c \
					display.c \
					init.c \
					parse_flags.c \
					parse_percent.c \
					parse_type.c \
					parse.c \
					printf.c \
					tools_f.c \
					tools_int.c \
					tools_o.c \
					tools_p.c \
					tools_x.c \
					tools.c \
					tools1.c


SOURCES = 	$(FT_CHAR_FOLDER) $(FT_LST_FOLDER) $(FT_STR_FOLDER) $(FT_MEM_FOLDER) $(FT_MEM_FOLDER) \
 			$(FT_PUT_FOLDER) $(FT_LIB_FOLDER) $(GET_NEXT_LINE) $(FT_PRINTF_FOLDER)

INCLUDES = -I./includes

OBJECTS = $(SOURCES:%.c=%.o)


vpath %.c ft_char
vpath %.c ft_lst
vpath %.c ft_str
vpath %.c ft_mem
vpath %.c ft_put
vpath %.c ft_lib
vpath %.c get_next_line
vpath %.c ft_printf


GCC = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c
		gcc $(GCC) $(INCLUDES) -c $< -o $@


clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
