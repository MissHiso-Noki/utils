# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoste <ccoste@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 15:48:01 by ccoste            #+#    #+#              #
#    Updated: 2023/02/16 16:48:09 by ccoste           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nom de l'archive
NAME = 

# Les fichiers de .c
SRC =

FLAGS = -Wall -Wextra -Werror
INC = -I includes/
HEADER_DIR = .
CC = cc

# specifie que OBJ represente les .c des SRC en .o
= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 

# "%.o : %.c" =".c.o :"
# Permet de construire des .o a partir de .c (c'est une regle generique)
# $< =	le nom de la premiere dependance (ici .c)
# $@ =	le nom de la cible (ici .o)
# -c :	ne link pas les fichiers sources et les transforme en .o
# - I :	include le directorie $(HEADERS)
%.o : %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INC) $(HEADER_DIR)

# Enleve les .o / -f = --force
clean :
	rm -rf 
	make clean -C 

# Apelle clean et enleve .a
fclean : clean
	rm -rf $(NAME)

# Apelle fclean et refait notre binaire
re : fclean all

# Phony evite le relinking
.PHONY : clean fclean
