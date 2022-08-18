NAME		= fractol

SRCS		= fractol.c operations.c

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
			$(RM) $(OBJS)
			$(RM) $(BOBJS)
			cd libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) libft/libft.a

re:		fclean all

.PHONY:		re fclean clean compile libft all $(NAME)
