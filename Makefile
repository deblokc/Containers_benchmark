# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnaton <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 19:13:09 by tnaton            #+#    #+#              #
#    Updated: 2022/11/30 12:10:12 by tnaton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT = test_ft

STD = test_std

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

PREC = 1

TEST = 0

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -Wshadow -O3 -g -std=c++98

all: $(FT) $(STD)
.PHONY: all

$(FT): $(SRC)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=ft -DPREC=$(PREC) -DTEST=$(TEST) $(SRC) -o $@
	
$(STD): $(SRC)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=std -DPREC=$(PREC) -DTEST=$(TEST) $(SRC) -o $@

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
