CC = gcc
FLAGS = -Werror -Wextra -Wall
OBJS = ft_printf.o writing.o parser.o args.o
OBJSFULL = $(addprefix $(OBJ)\, $(OBJS))
HEADERS = include\ft_printf.h src\internal\common.h

NAME = ft_printf

RMCMD = del

SRC = src
OBJ = obj
BIN = bin

all: $(OBJS)
	@if not exist $(BIN) mkdir $(BIN)
	@echo mkdir $(BIN)
	ar -rcs $(BIN)\$(NAME).a $(OBJSFULL)

$(NAME).a: all

%.o: $(SRC)\%.c
	@if not exist $(OBJ) mkdir $(OBJ)
	$(CC) $(FLAGS) -c -o $(OBJ)\$@ $^

re: fclean all

clean:
	$(RMCMD) $(OBJ)\*.o *.o

fclean:
	@if exist $(OBJ) rd /s /q $(OBJ)
	@echo rd /s /q $(OBJ)
	@if exist $(BIN) rd /s /q $(BIN)
	@echo rd /s /q $(BIN)

main.exe: $(NAME).a
	$(CC) main.c -L.\$(BIN) -l:$^ -o $(BIN)\main

run:
	.\$(BIN)\main.exe

rerun: fclean main.exe run

check:
	ar -t $(BIN)\$(NAME).a

test:
	$(CC) testing.c -o test.exe
	.\test.exe
	@$(RMCMD) test.exe

.PHONY: all test check run fclean clean re