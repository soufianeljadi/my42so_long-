NAME = so_long
NAME_B = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRC =	./Mandatory/get_next_line.c ./Mandatory/get_next_line_utils.c \
	./Mandatory/ft_printf.c  ./Mandatory/ft_printf_utils.c \
	./Mandatory/ft_split.c ./Mandatory/ft_strstr.c ./Mandatory/ft_strjoin.c \
	./Mandatory/handle_img.c ./Mandatory/get_map_info.c ./Mandatory/directions.c \
	./Mandatory/handle_keycode.c ./Mandatory/parse_map.c ./Mandatory/initialisation.c \
	./Mandatory/valid_path.c \
	./Mandatory/so_long.c 

SRC_B =	./Bonus/get_next_line_bonus.c ./Bonus/get_next_line_utils_bonus.c \
	./Bonus/ft_printf_bonus.c  ./Bonus/ft_printf_utils_bonus.c \
	./Bonus/ft_split_bonus.c ./Bonus/ft_strstr_bonus.c ./Bonus/ft_strjoin_bonus.c \
	./Bonus/handle_img_bonus.c ./Bonus/get_map_info_bonus.c ./Bonus/directions_bonus.c \
	./Bonus/handle_keycode_bonus.c ./Bonus/parse_map_bonus.c ./Bonus/initialisation_bonus.c \
	./Bonus/valid_path_bonus.c  ./Bonus/ft_itoa_bonus.c\
	./Bonus/so_long_bonus.c 

OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lmlx -framework OpenGL -framework AppKit

$(NAME_B): $(OBJ_B)
	@$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_B) -lmlx -framework OpenGL -framework AppKit

%.o: %.c ./Mandatory/so_long.h 
	@$(CC) $(CFLAGS) -o $@ -c $<
	
bonus/%.o: bonus/%.c  ./Bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

bonus : $(NAME_B)

clean:
	@$(RM)	$(OBJ)	$(OBJ_B)

fclean:	clean
	@$(RM)	$(NAME)	$(NAME_B)

re: fclean all

.PHONY: all clean fclean re bonus