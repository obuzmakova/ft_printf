NAME = libftprintf.a

GCC = gcc -c

SRC_DIR = srcs/
OBJ_DIR = obj/
LIB_DIR = libft/

SRC = ft_findfunction.c ft_genparser.c ft_parser.c ft_spec_c.c ft_spec_s.c ft_spec_p.c ft_spec_x.c

OBJ = $(patsubst %.c, %.o, $(SRC))
HEADER = includes
LIB = libft/libft.a

C_PATH = $(addprefix $(SRC_DIR), $(SRC))
O_PATH = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(O_PATH)
	cp $(LIB) ./$(NAME)
	ar -rc $(NAME) $(O_PATH)
	ranlib $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(GCC) $< -o $@ -I $(HEADER) -I $(LIB_DIR)
	make -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

clean:
	rm -f $(OBJ_PATH)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)

re: fclean all

.PHONY: all fclean clean re
