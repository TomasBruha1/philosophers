# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:15:26 by tbruha            #+#    #+#              #
#    Updated: 2025/03/26 20:54:13 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -g -pthread
HEADERS		= -I include/ # I don't need it?
RM			= rm -rf # force recursive remove
CC			= cc
MAKEFLAGS 	= --no-print-directory # silences "entering, leaving dir..."

SRC		= 	philosophers.c init.c utils.c #src/push_swap.c

OBJ		:=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(HEADERS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@echo "philo is clean"

fclean:	clean
	@$(RM) $(NAME)
	@echo "philo is super clean"

re:	fclean all

.PHONY:	all clean fclean re