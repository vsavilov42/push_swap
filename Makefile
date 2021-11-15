# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/06 19:18:22 by vsavilov          #+#    #+#              #
#    Updated: 2021/11/11 21:38:18 by vsavilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###	Compiler and flags	###

CC = gcc

CFLAGS = -Wall -Werror -Wextra

DEBUG: CFLAGS += -fsanitize=address -g3

###	Source items	###

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

SRCS_BONUS = checker.c \
			get_next_line.c \
			sort_rules_pa.c \
			ft_list_functions.c \
			maping.c \
			ft_split.c \
			isitsorted.c \
			parse.c \
			push_swap_error.c \
			push_swap_utils.c \
			push_swap_utils_2.c \
			sort_rules_r.c \
			sort_rules_rr.c \
			sort_rules_s.c

###	Directories ###

SRCDIR = src

OBJDIR = obj

BONUS_SRC_DIR = checker

BONUSDIR = b_obj

###	Program/s name/s ###

NAME = push_swap

BONUS = push_swap_checker

###	Objects dir	###

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
		@$(CC) $(CFLAGS) -I. -c $< -o $@

$(OBJDIR):
		@mkdir -p $(OBJDIR) 2> /dev/null

$(BONUSDIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUSDIR)
		@$(CC) $(CFLAGS) -I. -c $< -o $@

$(BONUSDIR):
		@mkdir -p $(BONUSDIR) 2> /dev/null

###	Create objects	###

OBJS_NAME = $(SRCS_NAME:%.c=%.o)

SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))

OBJS = $(addprefix $(OBJDIR)/, $(OBJS_NAME))


OBJS_BONUS_NAME = $(SRCS_BONUS:%.c=%.o)

SRC_BONUS = $(addprefix $(BONUS_SRC_DIR)/, $(SRCS_BONUS))

OBJS_BONUS = $(addprefix $(BONUSDIR)/, $(OBJS_BONUS_NAME))

###	Compile .o ###

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_BONUS)

### Rules can be executed ###

.PHONY: all clean fclean re bonus

all: $(NAME) $(BONUS)

debug: $(NAME)

bonus: $(BONUS)

clean:
	rm -rf $(OBJDIR) $(BONUSDIR)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all
