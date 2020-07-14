# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan <juan@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/17 16:53:54 by jdel-ros          #+#    #+#              #
#    Updated: 2020/07/14 15:47:02 by juan             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

HEAD_PATH	=					.
HEAD_NAME	=					includes/cubeddd.h minilibx_opengl_20191021/mlx.h
HEADER		=					$(addprefix $(HEAD_PATH)/,$(HEAD_NAME))
MINILIBX	=					libmlx.a
MINILIBXS	=					minilibx_opengl_20191021/libmlx.a
LIB			=					libft.a
LIBS		=					libft/libft.a
SRC_PATH	=					sources
SRCS_NAME	=					ft_raycasting_sprite.c ft_raycasting.c main.c \
								ft_parsing.c ft_parsing_two.c ft_parsing_three.c \
								ft_parsing_for.c ft_check_arg.c \
								ft_puterror.c ft_check_parsing.c ft_move.c \
								ft_bitmap.c ft_free.c ft_key.c ft_texture.c \
								ft_collision.c ft_verline.c

OBJS		= 					${SRCS:.c=.o}
NAME		= 					Cub3D
RM			= 					rm -f
FLAGS 		= 					-Wall -Wextra -Werror -g3
GFLAGS 		=					-lmlx -framework OpenGL -framework AppKit
SRCS 		= 					$(addprefix $(SRC_PATH)/,$(SRCS_NAME))
all:							$(MINILIBX) $(LIB) CUBE $(NAME)
%.o: %.c 						$(HEADER) $(LIBS) $(MINILIBXS)
								@echo "\033[0;32m[OK] \033[0m \033[0;33m Compiling:\033[0m" $<
								@gcc $(FLAGS) -c $< -o $@
$(NAME):						$(OBJS) $(HEADER)
								@gcc $(FLAGS) $(OBJS) -L minilibx_opengl_20191021 $(GFLAGS) $(LIBS) -o $(NAME) -lm
								@echo "\x1b[36m\n[OK] \033[0m \x1b[35m Compiling Cube3D\033[0m"
$(MINILIBX) :
								@$(MAKE) -C minilibx_opengl_20191021 all
$(LIB):
								@$(MAKE) -C libft all
clean:
								@$(MAKE) -C libft clean
								@$(MAKE) -C minilibx_opengl_20191021 clean
								@echo "\x1b[36m[OK] \033[0m \x1b[34m Removing ALL File object\033[0m"
								@$(RM) $(OBJS)
fclean:							clean
								@$(MAKE) -C libft fclean
								@echo "\x1b[36m[OK] \033[0m \x1b[32m All is Removing\033[0m"
								@$(RM) $(NAME)
re:								fclean all
CUBE:
								@echo ---------------------------------------------
								@echo "	 __,,  ,__, __,  __   _ , "
								@echo "	|   |  ||_)|__   __| |  \ "
								@echo "	|__ |__||_)|__   __| |_ / "
								@echo "	~~   ~~ ~  ~~    ~~  ~~   "
								@echo ""
.PHONY: 						clean fclean