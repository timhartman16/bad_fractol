SRCS            = fractol.c complex_operations.c mlx_hooks.c ft_atof.c ft_init.c \
					draw.c mandelbrot.c julia.c
OBJS            = $(SRCS:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          =  -g
LIBS            =  -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft
MLX             = libmlx.dylib
LIBFT           = ./libft/libft.a
NAME            = fractol

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)  $(LIBFT)
					gcc ${CFLAGS} -o ${NAME}  ${OBJS} ${LIBS}

$(LIBFT):
			$(MAKE) -C libft


clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME) $(MLX) $(LIBFT) ./mlx/$(MLX)

re:		fclean $(NAME)

.PHONY:	all clean fclean re libft