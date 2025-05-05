# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:15:26 by tbruha            #+#    #+#              #
#    Updated: 2025/05/05 16:42:46 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -pthread # -fsanitize=thread
HEADERS		= -I include/
RM			= rm -rf # force recursive remove
CC			= gcc
MAKEFLAGS 	= --no-print-directory # silences "entering, leaving dir..."

SRC		= 	philosophers.c init.c utils.c utils_2.c #src/push_swap.c

OBJ		:=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(HEADERS) -o $(NAME)
	@echo "Pasta is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ)
	@echo "Philos are clean."

fclean:	clean
	@$(RM) $(NAME)
	@echo "...and now super clean!"

re:	fclean all

.PHONY:	all clean fclean re