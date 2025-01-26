
NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fPIE
AR = ar rcs
RM = rm -f

SRCS_DIR = srcs/
OBJS_DIR = .objets/srcs/
INCLUDE_DIR = includes/

PARSING = $(addprefix parsing/, parse find_order find_next_move lst_clean)
UTILS = $(addprefix utils/, compare error free get_1 get_2 set_1 set_2 set_3)
LST_UTILS = $(addprefix lst_utils/, init handle)
MOVE = $(addprefix move/, put_move first_move move_1 move_2)

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, main $(PARSING) $(UTILS) $(LST_UTILS) $(MOVE)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, main $(PARSING) $(UTILS) $(LST_UTILS) $(MOVE)))

INCLUDES = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)libft -I$(INCLUDE_DIR)ft_printf

LIBFT = $(INCLUDE_DIR)libft/libft.a
PRINTF = $(INCLUDE_DIR)ft_printf/libftprintf.a

LIBS = $(LIBFT) $(PRINTF)

DIR_DUP = mkdir -p $(@D)

all : $(OBJS_DIR) $(LIBFT) $(PRINTF) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBS):
	@$(MAKE) -C $(INCLUDE_DIR)libft
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDES) -L$(INCLUDE_DIR)libft -lft -L$(INCLUDE_DIR)ft_printf -lftprintf -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	@$(MAKE) -C $(INCLUDE_DIR)libft clean
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf clean
	$(RM) $(OBJS)

fclean : clean
	@$(MAKE) -C $(INCLUDE_DIR)libft fclean
	@$(MAKE) -C $(INCLUDE_DIR)ft_printf fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re