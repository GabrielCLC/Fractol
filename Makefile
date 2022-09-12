NAME		= fractol

SRCS		= fractol.c fractol_utils.c color.c events.c mlx_utils.c validation.c 

OBJS		= $(SRCS:.c=.o)

MINILIBX	= -Lmlx -lmlx -framework OpenGL -framework appKit

LIBFT		= -Llibft -lft

CC			= cc

RM 			= rm -f

CFLAGS		= -Wall -Wextra -g#-Werror

.c.o:
			$(CC) $(CFLAGS) -c $(SRCS)

$(NAME):	$(OBJS) libft minilibx compile

all:		$(NAME)

minilibx:
			cd mlx && $(MAKE)

libft:
			cd libft && $(MAKE)

compile:
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME) 

clean:
			$(RM) $(OBJS)
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a
			cd mlx && $(MAKE) clean

re:			fclean all

norminette:
			norminette $(SRCS)

.PHONY:		re fclean clean compile libft all minilibx $(NAME) norminette
