UNAME := $(shell uname)

NAME		= fractol

SRCS		= fractol.c fractol_utils.c color.c events.c mlx_utils.c 

OBJS		= $(SRCS:.c=.o)

ifeq ($(UNAME), Linux)
MINILIBX	= -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX			= mlx_linux
else
MINILIBX	= -Lmlx_mac -lmlx -framework OpenGL -framework appKit
MLX			= mlx_mac
endif

LIBFT		= -Llibft -lft

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra -g#-Werror

.c.o:
			$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):	$(OBJS) libft minilibx compile

all:		$(NAME)

minilibx:
			cd $(MLX) && $(MAKE)

libft:
			cd libft && $(MAKE)

compile:
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -D $(UNAME) -o $(NAME) 

clean:
			$(RM) $(OBJS)
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a
			cd $(MLX) && $(MAKE) clean

re:			fclean all

norminette:
			norminette $(SRCS)

.PHONY:		re fclean clean compile libft all minilibx $(NAME) norminette
