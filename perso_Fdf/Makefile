SRCS = main.c map.c color.c pixel_color.c

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

MINILIB_PATH_MACOS = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
MINILIB_PATH_LINUX = -I minilibx-linux -L minilibx-linux -lmlx -lXext -lX11
LIBFT_PATH = -I Libft_fdf -L Libft_fdf -lft_fdf

CC = gcc

%.o: %.c fdf.h
			${CC} -I. ${MINILIB_PATH_LINUX} ${LIBFT_PATH} -MMD -c $< -o ${<:.c=.o}

### si la compilation echoue -> enlever le PATH_MACOS et compiler macos avec les SRCS directement

macos: 	
		$(MAKE) -C minilibx_macos/ all
		$(MAKE) -C Libft_fdf/ all
		clear
		$(CC) ${SRCS} ${MINILIB_PATH_MACOS} ${LIBFT_PATH} 

linux: ${OBJS}
		$(MAKE) -C minilibx-linux/ all
		$(MAKE) -C Libft_fdf/ all
		clear
		$(CC) ${OBJS} ${MINILIB_PATH_LINUX} ${LIBFT_PATH} 

macos_run: macos
			./a.out

linux_run: linux
			./a.out

clean:	
		rm -f ${OBJS} ${DEPS}
		$(MAKE) -C minilibx_macos/ clean
		$(MAKE) -C minilibx-linux/ clean
		$(MAKE) -C Libft_fdf/ clean
		rm -f a.out
		clear

fclean:	clean
		$(MAKE) -C Libft_fdf/ fclean
		clear


-include $(DEPS)

re:	fclean all

.PHONY: clean fclean re bonus linux macos linux_run macos_run
