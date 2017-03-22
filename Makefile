# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbodak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 16:40:31 by mbodak            #+#    #+#              #
#    Updated: 2017/02/21 16:41:09 by mbodak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
GCC		= gcc
FLAG	= -Wall -Wextra -Werror
SRC		= *.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		mv libft/libft.a ./$(NAME)
		$(GCC) -c $(FLAG) $(SRC) -I ./
		ar rv $(NAME) $(OBJ)
		ranlib $(NAME)

clean :
		make clean -C libft/
		rm -rf $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : 	fclean all
