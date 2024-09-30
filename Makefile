CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c ft_convert_base.c ft_convert_base2.c ft_ultoa.c ft_ltoa.c \
ft_intputnbr_fd.c ft_intputchar_fd.c ft_intputstr_fd.c ft_strtoupper.c \
ft_strtolower.c
OBJS = $(SRCS:.c=.o)
INCLUDE = libftprintf.h

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@$(AR) rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
