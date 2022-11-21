# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblondee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 15:19:23 by eblondee          #+#    #+#              #
#    Updated: 2022/07/05 11:24:21 by eblondee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	./Mandatory/main.c \
		./Mandatory/Check_Error/ft_check.c \
		./Mandatory/Check_Error/ft_check_map.c \
		./Mandatory/Window/ft_window.c \
		./Mandatory/Map/ft_map.c \
		./Mandatory/Utils/ft_free.c \
		./Mandatory/Utils/ft_image.c \
		./Mandatory/Utils/ft_find.c \
		./Mandatory/Utils/ft_move.c \
		./Mandatory/Utils/ft_end.c \

SRCSB = ./Bonus/main_bonus.c \
		./Bonus/Check_Error/ft_check_bonus.c \
		./Bonus/Check_Error/ft_check_map_bonus.c \
		./Bonus/Check_Error/ft_check_args_bonus.c \
		./Bonus/Window/ft_window_bonus.c \
		./Bonus/Map/ft_map_bonus.c \
		./Bonus/Utils/ft_free_bonus.c \
		./Bonus/Utils/ft_image_bonus.c \
		./Bonus/Utils/ft_find_bonus.c \
		./Bonus/Utils/ft_move_bonus.c \
		./Bonus/Utils/ft_end_bonus.c \
		./Bonus/Utils/ft_display_string_bonus.c \
		./Bonus/Enemies/ft_enemies_bonus.c \
		./Bonus/Enemies/ft_move_enemies_bonus.c \

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

NAME = so_long

NAMEB = so_long_bonus

CC = gcc

RM = rm -rf

DIR_LIB = ./libft/

LIB = libft.a

MINILIBX = ./mlx_linux/

CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	${NAME}

bonus :	${NAMEB}

$(NAME):	${OBJS}
	make -C ${DIR_LIB} ${LIB}
	make -C ${MINILIBX}
	${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${DIR_LIB}${LIB} -o ${NAME}

$(NAMEB) :	${OBJSB} 
	make -C ${DIR_LIB} ${LIB}
	make -C ${MINILIBX}
	${CC} ${CFLAGS} ${OBJSB} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ${DIR_LIB}${LIB} -o ${NAMEB}

clean:
	@make -sC ${DIR_LIB} clean
	@make -sC ${MINILIBX} clean
	@${RM} ${OBJS}
	@${RM} ${OBJSB}
	@printf "All object were cleaned\n"

fclean: clean
	@${RM} ${DIR_LIB}${LIB}
	@${RM} ${NAME}
	@${RM} ${NAMEB}
	@printf "All exectutable were cleaned\n"

re: fclean all

.PHONY: all clean fclean re bonus
