##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	= pamela.so

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -Wfatal-errors -I ./include/ -fPIC -fno-stack-protector
LDFLAG	= -lcryptsetup

CP	= cp -f
RM	= rm -rf
MKDIR	= mkdir -p

SRCS	= $(foreach dir,$(shell find srcs -type d),$(wildcard $(dir)/*.c))
OBJS	= $(SRCS:.c=.o)
DEPS	= $(SRCS:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	 @echo "Building $(NAME)..."
	 @$(CC) -o $(NAME) $(OBJS) -shared -rdynamic $(LDFLAG)

clean:
	@echo "Cleaning temporary files..."
	@rm -f $(OBJS)
	@rm -f $(DEPS)

fclean:	clean
	@echo "Cleaning executable..."
	@rm -f $(NAME)

re: fclean all

install:
		@make && .bin/.installer

uninstall: 
	fclean && .bin/.uninstaller

reinstall: uninstall install

check:
	.bin/.check

test:
	@echo "Sorry you cannot test !\n";

%.o: %.c
	@echo "=>" $<
	@$(CC) -c $< -o $@ $(CFLAGS)

-include $(DEPS)

.PHONY:	all clean fclean re install uninstall reinstall check test
