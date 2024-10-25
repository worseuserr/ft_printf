CC := gcc
FLAGS := -Werror -Wextra -Wall
FILES := main.c ft_printf.c
NAME := a.exe
RMCMD := del

all:
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

re: clean all

clean:
	$(RMCMD) $(NAME)

run: re
	.\$(NAME)