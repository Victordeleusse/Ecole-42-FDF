SRCS = main.c map.c color.c pixel_color.c line.c vertex.c hook.c draw.c transformation.c free.c pixel.c
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

EXEC = FdF

MINILIB_PATH_MACOS = -I minilibx_macos -L minilibx_macos -lmlx -lm -framework OpenGL -framework AppKit
MINILIB_PATH_LINUX = -I minilibx-linux -L minilibx-linux -lmlx -lm -lXext -lX11
LIBFT_PATH = -I Libft_fdf -L Libft_fdf -lft_fdf

CC = cc
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wextra

CFLAGS += -fsanitize=address,undefined -g2
# CFLAGS += -valgrind

%.o: %.c fdf.h
			${CC} -I. ${MINILIB_PATH_LINUX} ${LIBFT_PATH} -MMD -c $< -o ${<:.c=.o}

### si la compilation echoue -> enlever le PATH_MACOS et compiler macos avec les SRCS directement

all: linux_run

macos: 	
		$(MAKE) -C minilibx_macos/ all
		$(MAKE) -C Libft_fdf/ all
		clear
		$(CC) -o ${EXEC} $(CFLAGS) ${SRCS} ${MINILIB_PATH_MACOS} ${LIBFT_PATH} 

linux: ${OBJS}
		$(MAKE) -C minilibx-linux/ all
		$(MAKE) -C Libft_fdf/ all
		clear
		$(CC) -o ${EXEC} $(CFLAGS) ${OBJS} ${MINILIB_PATH_LINUX} ${LIBFT_PATH} 

macos_run: macos

linux_run: linux

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
