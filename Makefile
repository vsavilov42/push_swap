# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 19:18:22 by vsavilov          #+#    #+#              #
#    Updated: 2021/11/11 17:31:50 by vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME = ft_list_functions.c \
			ft_split.c \
			isitsorted.c \
			main.c \
			maping.c \
			parse.c \
			push_swap_error.c \
			push_swap_utils.c \
			push_swap_utils_2.c \
			sort_chunks.c \
			sort_big_chunks.c \
			junk_chunks.c \
			sort_less_five.c \
			sort_rules_pa.c \
			sort_rules_r.c \
			sort_rules_rr.c \
			sort_rules_s.c


CFLAGS = -Wall -Werror -Wextra

CC = gcc

SRCDIR = src

OBJDIR = obj

NAME = push_swap

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_NAME))

.PHONY: all clean fclean re bonus

all: $(NAME)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

debug: CFLAGS += -fsanitize=address -g3
debug: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
		@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
		@mkdir -p $(OBJDIR) 2> /dev/null

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
