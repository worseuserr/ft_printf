CC := gcc
FLAGS := -g -fdiagnostics-color=always -Werror -Wextra -Wall
FILES := main.c src\ft_printf.c src\writing.c src\parser.c
NAME := out.exe
RMCMD := del

all:
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

re: clean all

clean:
	$(RMCMD) $(NAME)

fclean:
	$(RMCMD) *.exe

run: re
	$(NAME)

test:
	$(CC) testing.c -o test.exe
	.\test.exe
	@$(RMCMD) test.exe