cmake_minimum_required(VERSION 3.14)
project(RTv1 C)

set(CMAKE_C_STANDARD 99)

add_executable(RTv1 rtv1.c vector_utils.c vector_scal.c)

find_library(SDL2 SDL2
		PATH
		./frameworks)

find_library(SDL2_image SDL2_image
		PATH
		./frameworks)

target_link_libraries(RTv1 ${SDL2} ${SDL2_image})
