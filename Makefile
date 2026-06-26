CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
INCLUDE = -Iinclude -Ilib
NAME = push_swap.out
LIBFT_DIR = ./lib
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
OBJS_DIR = obj

CFILES = push_swap.c \
	core/ft_sort.c \
	core/ft_sort_utils.c \
	core/ft_sort_chunks.c \
	operations/push/ft_push.c \
	operations/rotate/ft_rotate.c \
	parsing/ft_parse.c \
	parsing/ft_parse_stack.c \
	parsing/ft_parse_utils.c \
	parsing/ft_parse_utils_2.c \
	utils/ft_utils.c \
	utils/ft_bench.c \
	utils/ft_stack_utils.c \
	utils/ft_stack_utils_2.c \

OFILES = $(CFILES:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(OFILES))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) -L./lib -lft -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(INCLUDE) -o $@ 

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re libft
