# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 12:45:37 by ovirchen          #+#    #+#              #
#    Updated: 2018/05/21 19:02:53 by atlekbai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SOURCES = main.cpp \
        Game.cpp \
        Asteroid.cpp \
        Player.cpp \
        Rocket.cpp \
        Enemy.cpp \
        Stars.cpp \
        SuperBoss.cpp \

SRCS = $(addprefix src/,$(SOURCES))

OBJ = $(SOURCES:.cpp=.o)

HEADERS = inc/Game.hpp \
        inc/Asteroid.hpp \
        inc/Player.hpp \
        inc/Rocket.hpp \
        inc/Enemy.hpp \
        inc/Stars.hpp \
        inc/SuperBoss.hpp \

CC = clang++

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -lncurses
	@echo "\033[32mft_retro\033[33m MAKED\033[0m"

$(OBJ): $(SRCS) $(HEADERS)
	$(CC) $(FLAGS) -c $(SRCS) -I $(HEADERS)

clean:
	rm -f $(OBJ)
	@echo "\033[33mCLEANED\033[0m"

fclean: clean
	rm -f $(NAME)
	@echo "\033[33mCLEANED ALL\033[0m"

re: fclean all

.PHONY: all clean fclean re