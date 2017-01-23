# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compilator.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 20:05:49 by tfontain          #+#    #+#              #
#    Updated: 2017/01/23 20:08:18 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
rm -f libft/*.o
rm -f libft/libft.a
rm -f *.o
