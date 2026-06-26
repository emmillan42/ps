# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 13:30:23 by durisosa          #+#    #+#              #
#    Updated: 2026/06/26 13:47:11 by durisosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar rcs
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
RM = rm -rf
INCLUDE = -I.

CFILES = ft_atoi.c \
ft_strlen.c \
ft_strncmp.c \
ft_count_words.c \
printf/ft_flags_utils.c \
printf/ft_flags.c printf/ft_printf.c \
printf/ft_printc.c printf/ft_printf_utils.c \
printf/ft_printf_xtoa.c printf/ft_printhex.c \
printf/ft_printint.c printf/ft_printptr.c \
printf/ft_printstr.c printf/ft_printuint.c

OBJS = $(CFILES:.c=.o)

$(NAME): $(OBJS)
	$(AR) ${NAME} $^

%.o: %.c
	@echo "Creating object files";
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
