
NAME = push_swap

#COMPIL
CC = cc
CFLAGS = -Wall -Wextra -Werror 


#DIRECTORY
SRC_PATH = src/
OBJ_PATH = obj/

#SOURCES
SRC =  	sort_algo.c\
		error_utils.c\
		free_utils.c\
		ft_atoi.c\
		ft_split.c\
		init_stack.c\
		list_utils.c\
		push_nodes_ab.c\
		reverse_rotate_nodes.c\
		rotate_nodes.c\
		swap_nodes.c\
		sort_three_five_arg.c\
		sort_utils.c\
		sort_utils_2.c\
		tmp_tab_functions.c\
		main.c

SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)
	
fclean: clean
	rm -f $(NAME)

re: fclean all	

.PHONY: all clean fclean re
