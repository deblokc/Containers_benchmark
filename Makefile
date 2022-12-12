# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 19:13:09 by tnaton            #+#    #+#              #
#    Updated: 2022/12/12 18:13:16 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT = test_ft

STD = test_std

SRC = main.cpp

INC = include.hpp

OBJ = $(SRC:.cpp=.o)

PREC = 1

TEST = 0

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -O3 -g -std=c++98

all: $(FT) $(STD)
.PHONY: all

$(FT): $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=ft -DPREC=$(PREC) -DTEST=$(TEST) $(SRC) -o $@
	
$(STD): $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=std -DPREC=$(PREC) -DTEST=$(TEST) $(SRC) -o $@

$(OBJ): $(INC)

$(SRC): $(INC)

clean:
	rm -rf $(OBJ) ft.log std.log
.PHONY: clean

fclean: clean
	rm -rf $(FT) $(STD)
.PHONY: fclean

test: $(FT) $(STD)
	sh test.sh
.PHONY: test

re: fclean all
.PHONY: re

.SECONDARY : $(OBJ)
