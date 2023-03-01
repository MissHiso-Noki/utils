# Nom de l'archive
NAME	= # libft.a ou libft (executable (./libft))

# compilateur utiliser
CC = cc

# les flags pour la compialtion
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = #nom_du_fichier_avec_.c/
SRC_PATH_B = #nom_du_fichier_B_avec_.c/

OBJ_PATH = #nom_ou_on_veux_mettre_fichier.o/
OBJ_PATH_B = #nom_ou_on_veux_mettre_fichier_B.o/

# les fichier de .c de la partie principale
SRC = #fihier.c \
			fichier2.c

# les fichier .c de la partie bonus
SRC_B = # fichier_B.c \
				fichier2_B.c

# add et concatene SRC_PATH avec SRC
SRCS = $(addprefix $(SRC_PATH), $(SRC))
# specifie aue OBJ represente les .c des SRC en .o
OBJ = $(SRC:.c=.o)
# add et concatene OBJ_PATH avec OBJ, ex strapi.c
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))
# includes quand .h dans un fichier
INCS = -I #./nom_fichier/

# add et concatene SRC_PATH avec SRC
SRCS_B = $(addprefix $(SRC_PATH_B), $(SRC_B))
# specifie aue OBJ_B represente les .c des SRC_B en .o
OBJ_B = $(SRC_B:.c=.o)
# add et concatene OBJ_PATH avec OBJ, ex strapi.c
OBJS_B = $(addprefix $(OBJ_PATH_B), $(OBJ_B))
# includes quand .h dans un fichier
INCS_B = -I #./nom_fichier/

#commande qui execute ce qu'il y a dedans
all : $(OBJ_PATH_B) $(OBJ_PATH) $(NAME)

#creer les .o en compilant avec les flags
$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)
#creer les .o en compilant avec les flags
$(OBJ_PATH_B)%.o : $(SRC_PATH_B)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS_B)

#crer fichier pour mettre .o
$(OBJ_PATH):
	mkdir $(OBJ_PATH)
#crer fichier pour mettre .o
$(OBJ_PATH_B):
	mkdir $(OBJ_PATH_B)

#execute et compile
$(NAME)	: $(OBJS) $(OBJS_B)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		$(CC) $(FLAGS) $(OBJS_B) -o $(NAME)

# Enleve les .o / -f = --force et le fichiers assigner
clean	:
	rm -f $(OBJ_PATH) $(OBJ_PATH_B)

# Appelle clean et enleve le libft.a ou libft
fclean	: clean
	rm -f $(NAME)

# Apelle fclean et refait notre binaire
re	: fclean all

# Phony evite le relinking
.PHONY : all clean fclean re
