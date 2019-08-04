# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkuvalis <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 18:04:23 by kkuvalis          #+#    #+#              #
#    Updated: 2019/08/04 16:22:49 by cfahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC  = rtv1.c vector_scal.c vector_utils.c atof.c \
	   read_scene1.c read_scene2.c gnl/get_next_line.c check_intersect.c \
	   help_utils.c intesect.c init.c help_computelight.c \
	   ray.c source.c sdl_utils.c 

OBJ  = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

LIBFT = gnl/libft/libft.a

INC_LIB = libft
LIBFT_PATH = gnl/libft

HEAD = rtv1.h parser.h get_next_line.h

INCLUDES = -I./libft/ -I./frameworks/SDL2.framework/Headers

FRAMEWORKS = -F./frameworks -rpath ./frameworks -framework SDL2 -framework SDL2_ttf -framework SDL2_mixer -framework SDL2_image

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDES) $(FRAMEWORKS) -I$(INC_LIB) -o $(NAME)
			
$(LIBFT):
		make -C $(LIBFT_PATH)

%.o : %.c rtv1.h 
		gcc $(FLAGS)  -c $< -o $@ -I$(INC_LIB)

clean:
		make -C $(LIBFT_PATH) clean
			rm -f *.o

fclean: clean
			rm -f $(OBJ)
				rm -f $(NAME)

re: fclean all
		make -C $(LIBFT_PATH) re
