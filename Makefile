#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylesik <ylesik@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 21:30:45 by ylesik            #+#    #+#              #
#    Updated: 2018/10/03 21:30:46 by ylesik           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

FLAG = -Wall -Wextra -Werror

NCUR = -lncurses

SRC = main.cpp Ncurses.cpp Bullet.cpp Character.cpp Enemy.cpp \
Game.cpp Player.cpp

RUN = clang++

OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

%.o : %.cpp
	@$(RUN) $(FLAG) -o $@ -c $<

$(NAME): $(OBJ)
	@$(RUN) $(FLAG) $(NCUR) $(OBJ) -o $(NAME)
	@echo "ft_retro compiled"

#$(RUN) −lncurses $(OBJ) -o $(NAME)
#@ar rc $(NAME) $(OBJ_PF) $(OBJ_LIB). #$(FLAG) -lncurses

clean:
	@rm -f $(OBJ)
	@echo "ft_retro cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "ft_retro fcleaned"

re:	fclean all

