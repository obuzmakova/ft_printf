NAME = libftprintf.a

GCC = gcc -c

FLAG = -Wall -Wextra -Werror

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft

SRC = ft_findfunction.c ft_genparser.c ft_parser.c ft_spec_c.c ft_spec_s.c ft_spec_p.c ft_spec_x.c ft_spec_f.c \
put_and_width_x.c ft_spec_id.c ft_spec_id_2.c float_1.c float_2.c ft_printf.c color.c ft_spec_id_1.c spec_r.c \
ft_helper_out.c color_check.c

HEADER = includes
LIB = libft/libft.a

C_PATH = $(addprefix $(SRC_DIR), $(SRC))
O_PATH = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	@make -C $(LIB_DIR) fclean && make -C $(LIB_DIR)
	@cp $(LIB) ./$(NAME)
	@ar -rc $(NAME) $(O_PATH)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(GCC) $(FLAG) -I $(HEADER) -o $@ -c $<
	
fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_DIR)

clean:
	@/bin/rm -f $(O_PATH)
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

re: fclean all

.PHONY: fclean re all clean
