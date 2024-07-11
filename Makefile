# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youchen <youchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 13:34:52 by youchen           #+#    #+#              #
#    Updated: 2024/07/11 09:10:41 by youchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name = cub3d
src= excution/cub3d.c excution/movement_extra_utils.c excution/utils.c excution/raycasting.c excution/cast_vert_ray.c excution/cast_horz_ray.c excution/ray_util.c excution/movment.c excution/movement_utils.c excution/render_walls.c parsing/parse_1.c parsing/utils.c parsing/list.c parsing/get_next_line_utils.c parsing/get_next_line.c parsing/utils_2.c parsing/parse_3.c parsing/parse_2.c parsing/ft_memset.c parsing/ft_strchr.c parsing/parse_4.o
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

