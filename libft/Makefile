# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaddoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/08 09:09:52 by afaddoul          #+#    #+#              #
#    Updated: 2019/05/11 18:15:29 by afaddoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =libft.a

all : $(NAME)

$(NAME) :
	gcc -Wextra -Wall -Werror -c *.c libft.h
	ar rc $(NAME) *.o

clean :
	/bin/rm -f *.o
	/bin/rm -f *.gch

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

