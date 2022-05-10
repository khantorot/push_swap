# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glychest <glychest@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 17:37:37 by glychest          #+#    #+#              #
#    Updated: 2020/10/31 17:39:45 by glychest         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker
LIBFT = libft
SRCDIR = sources
OBJDIR = objects

FFLAGS = -Wall -Wextra -Werror
LFLAGS = -L $(LIBFT) -lft
HEADER_FILES = ./includes/push_swap.h

FILES_PS = 	push_swap.c\
			sort.c\
			s_a_p.c\
			s_b_p.c
		
FILES_CM = 	init.c\
			chunk.c\
			chunk_part.c\
			exit_free.c\
			oper.c\
			oper_a.c\
			oper_b.c\
			oper_ab.c\
			parser.c\
			tools.c
		
FILES_CH = 	checker.c

SRCS_CH = $(addprefix $(SRCDIR)/,$(FILES_CH))
SRCS_CM = $(addprefix $(SRCDIR)/,$(FILES_CM))
SRCS_PS = $(addprefix $(SRCDIR)/,$(FILES_PS))

OBJS_CH = $(addprefix $(OBJDIR)/,$(FILES_CH:.c=.o))
OBJS_CM = $(addprefix $(OBJDIR)/,$(FILES_CM:.c=.o))
OBJS_PS = $(addprefix $(OBJDIR)/,$(FILES_PS:.c=.o))

INCLUDES = includes

all: libft.a $(NAME_CH) $(NAME_PS)
$(NAME_CH): $(OBJS_CM) $(OBJS_CH) $(HEADER_FILES)
	gcc $(FFLAGS) -o $(NAME_CM) $(NAME_CH) $(OBJS_CM) $(OBJS_CH) $(LFLAGS)

$(NAME_PS): $(OBJS_CM) $(OBJS_PS) $(HEADER_FILES)
	gcc $(FFLAGS) -o $(NAME_CM) $(NAME_PS) $(OBJS_CM) $(OBJS_PS) $(LFLAGS)

libft.a:
	make -C $(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER_FILES)
	mkdir -p objects
	gcc $(FFLAGS) -I $(LIBFT) -I $(INCLUDES) -o $@ -c $<

clean: 
	
	rm -rf $(OBJDIR)
	make -C $(LIBFT) clean

fclean: clean
	make -C $(LIBFT) fclean
	rm -rf $(NAME_CH)
	rm -rf $(NAME_PS)

re: fclean all

.PHONY: all clean fclean re