NAME		= fractol

SRCS		= fractol.c operations.c fractol_utils.c color.c 

OBJS		= $(SRCS:.c=.o)

MINILIBX	= -Lmlx -lmlx -framework OpenGL -framework appKit

LIBFT		= -Llibft -lft

MATH		= -lm

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra #-Werror

.c.o:
			$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):	$(OBJS) libft minilibx compile

all:		$(NAME)

minilibx:
			cd mlx && $(MAKE)

libft:
			cd libft && $(MAKE)

compile:
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) $(MATH) -o fractol 

clean:
			$(RM) $(OBJS)
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a
			cd mlx && $(MAKE) clean

re:		fclean all

.PHONY:		re fclean clean compile libft all minilibx $(NAME)
