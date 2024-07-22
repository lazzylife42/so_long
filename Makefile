# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 15:31:24 by smonte-e          #+#    #+#              #
#    Updated: 2023/11/21 14:07:54 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
DIR_SRC = src/
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft
MLX = minilibx
RM = rm -f
OPTIONS = -Imlx -Ilibft
INCLUDES = -I/opt/X11/include -Imlx

SRC =		 src/main.c \
			src/map.c \
			src/map2.c \
			src/copy_map.c \
			src/player.c \
			src/booba.c \
			src/state.c \
			src/error.c \
			src/error2.c \
			src/flood_fill.c

SRC_BONUS = src/main.c \
			src/map.c \
			src/map2.c \
			src/copy_map.c \
			src/player.c \
			src/booba.c \
			src/error.c \
			src/error2.c \
			src/flood_fill.c \
			src/state_bonus.c

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -sC $(MLX)
	gcc $(CFLAGS) $(OBJS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(OPTIONS)$(DIR_SRC) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	$(MAKE) -C $(LIBFT)

$(MLX):
	$(MAKE) -sC $(@D)

bonus: fclean $(OBJS_BONUS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -sC $(MLX)
	gcc $(CFLAGS) $(OBJS_BONUS) -L./$(LIBFT) -lft -L./$(MLX) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: clean fclean all re
