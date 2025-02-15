# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 16:15:26 by tbruha            #+#    #+#              #
#    Updated: 2025/02/15 21:21:15 by tbruha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# check fractol Makefile and make changes to the Makefile logic
# future: CFLAGS, HEADERS, LIBS, INCLUDE all separate

NAME 		= philosophers
HEADERS 	= -I include
LIBS 		= # Will I have one here??
FLAGS 		= -Wall -Wextra -Werror -pthread
INCLUDE		= 
MAKEFLAGS	= --no-print-directory # silences "entering, leaving dir..."
RM			= rm -fr

SRC 		= 

OBJ 		= 

all: ($NAME)

clean:

fclean:

re: fclean ($NAME)

PHONY: clean fclean re 