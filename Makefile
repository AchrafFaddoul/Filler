# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/11 17:42:24 by afaddoul          #+#    #+#              #
#    Updated: 2019/08/16 10:54:48 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = afaddoul.filler
FLAGS = -Wextra -Wall -Werror
HEADER_FILES = includes/filler.h includes/get_next_line.h

FILES = srcs/main.c srcs/get_next_line.c
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
