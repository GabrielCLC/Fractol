NAME		= fractol

SRCS		= fractol.c operations.c fractol_utils.c color.c 

MINILIBX	= -Lmlx -lmlx -framework OpenGL -framework appKit

LIBFT		= -Llibft -lft

MATH		= -lm

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra #-Werror

$(NAME):	libft minilibx compile

all:		$(NAME)

minilibx:
			cd mlx && $(MAKE)

libft:
			cd libft && $(MAKE)

compile:
			$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) $(MATH) -o fractol 

clean:
			cd libft && $(MAKE) clean
			cd mlx && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a

re:		fclean all

.PHONY:		re fclean clean compile libft all minilibx $(NAME)
