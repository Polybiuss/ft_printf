NAME = libftprintf.a
SOURCES = \
	ft_printf.c \
	ft_select.c \
	ft_putchar_printf.c \
	ft_putint_printf.c \
	ft_putptr_printf.c \
	ft_putstr_printf.c \
	ft_putuint_printf.c \
	ft_putx_printf.c \
	ft_putxupper_printf.c \

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rcs $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
