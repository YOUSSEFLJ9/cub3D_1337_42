# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymomen <ymomen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 13:34:52 by youchen           #+#    #+#              #
#    Updated: 2024/07/16 09:13:31 by ymomen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = cub3d
src= mandatory/excution/cub3d.c mandatory/excution/movement_extra_utils.c mandatory/excution/utils.c mandatory/excution/raycasting.c mandatory/excution/cast_vert_ray.c mandatory/excution/cast_horz_ray.c mandatory/excution/ray_util.c mandatory/excution/movment.c mandatory/excution/movement_utils.c mandatory/excution/render_walls.c mandatory/parsing/parse_1.c mandatory/parsing/utils.c mandatory/parsing/list.c mandatory/parsing/get_next_line_utils.c mandatory/parsing/get_next_line.c mandatory/parsing/utils_2.c mandatory/parsing/parse_3.c mandatory/parsing/parse_2.c mandatory/parsing/ft_memset.c mandatory/parsing/ft_strchr.c mandatory/parsing/parse_4.o
objs = $(src:.c=.o)
flags = -Wall -Wextra -Werror -Ofast 
cc = cc -g
all: $(name)

$(name): $(objs)
	$(cc) $(flags) -o $(name) $(objs) ./MLX42/build/libmlx42.a -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

%.o: %.c cub3d.h
	$(cc) $(flags) -c $< -o $@

clean:
	rm -f $(objs)

fclean: clean
	rm -f $(name)
re: fclean all

