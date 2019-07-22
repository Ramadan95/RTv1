cmake_minimum_required(VERSION 3.14)
project(SDL C)

set(CMAKE_C_STANDARD 99)

add_executable(SDL main.c rtv1.c parser.c rtv1.h parser.h parse_obj.c vector_utils.c vector_scal.c)

find_library(SDL2 SDL2
		PATH
		./frameworks)

find_library(SDL2_image SDL2_image
		PATH
		./frameworks)

target_link_libraries(SDL ${SDL2} ${SDL2_image})
