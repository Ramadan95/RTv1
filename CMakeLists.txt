cmake_minimum_required(VERSION 3.14)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_EXE rtv1.c vector_utils.c vector_scal.c atof.c check_intersect.c read_scene1.c read_scene2.c gnl/libft/ft_strchr.c gnl/libft/ft_putendl.c gnl/libft/ft_strstr.c gnl/get_next_line.c
		gnl/libft/ft_joincatfree.c gnl/libft/ft_strdup.c gnl/libft/ft_strncpy.c gnl/libft/ft_strnew.c gnl/libft/ft_strlen.c gnl/libft/ft_strcpy.c
		gnl/libft/ft_putstr.c gnl/libft/ft_strcmp.c gnl/libft/ft_strdel.c gnl/libft/ft_putchar.c gnl/libft/ft_memcpy.c gnl/libft/ft_lstnew.c
		gnl/libft/ft_atoi.c gnl/libft/ft_isdigit.c gnl/libft/ft_lstadd.c gnl/libft/ft_strcat.c source.c init.c help_utils.c sdl_utils.c intesect.c ray.c check_intersect.c help_computelight.c)

include_directories("gnl" "gnl/libft")


add_executable(RTv1 ${SOURCE_EXE})

find_library(SDL2 SDL2
		PATH
		./frameworks)

find_library(SDL2_image SDL2_image
		PATH
		./frameworks)

target_link_libraries(RTv1 ${SDL2} ${SDL2_image})
