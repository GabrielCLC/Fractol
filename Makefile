NAME		= fractol

SRCS		= fractol.c operations.c fractol_utils.c mandelbrot.c julia.c

CC		= cc

RM 		= rm -f

CFLAGS		= -Wall -Wextra #-Werror

$(NAME):	libft compile

all:		$(NAME)

libft:
			cd libft && $(MAKE)

compile:
			$(CC) $(CFLAGS) $(SRCS) -o fractol -L./libft -lft -lm

clean:
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a

re:		fclean all

.PHONY:		re fclean clean compile libft all $(NAME)
