# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 17:42:24 by afaddoul          #+#    #+#              #
#    Updated: 2019/08/31 17:50:41 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = afaddoul.filler
FLAGS = -g -Wextra -Wall -Werror
HEADER_FILES = includes/filler.h includes/get_next_line.h

FILES = srcs/main.c srcs/free_functions.c srcs/parsing_game_data.c srcs/board.c srcs/token.c srcs/prepare_heat_map.c srcs/heat_map_algorithm.c srcs/token_processing.c  srcs/get_next_line.c
OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER_FILES)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS)  $< -o $@ -c 
clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C ./libft

re : fclean all
