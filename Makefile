NAME = libasm.a
PROGRAM = main

SRC = main.c
SRC_ASM := ft_strlen.s
SRC_ASM += ft_strcpy.s
SRC_ASM += ft_strcmp.s


OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_ASM = $(SRC_ASM:%.s=$(OBJ_DIR)/%.o)

OBJ_DIR = ./obj
SRC_DIR = ./src

all: $(NAME)

vpath %.s $(SRC_DIR)
vpath %.c ./

$(NAME): $(OBJ_DIR) $(OBJ_ASM)
	ar -rcs $(NAME) $(OBJ_ASM)

$(PROGRAM): $(OBJ_DIR) $(NAME) $(OBJ)
	gcc -o $(PROGRAM) $(OBJ) $(NAME)

run: $(PROGRAM)
	./$(PROGRAM)

$(OBJ_DIR)/%.o: %.s
	nasm -g -f elf64 $< -o $@

$(OBJ_DIR)/%.o: %.c
	gcc -g -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	$(RM) vgcore.*
	$(RM) $(OBJ) $(OBJ_ASM)

fclean: clean
	$(RM) $(NAME) $(PROGRAM)

re: fclean all
