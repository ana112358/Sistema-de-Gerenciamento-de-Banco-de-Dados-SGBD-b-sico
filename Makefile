FLAGS= -g -std=c99 -Wall -Wextra -Werror -pedantic

all: projeto
projeto: projeto.o func1.o func2.o func3.o
	gcc projeto.o func1.o func2.o func3.o -o projeto $(FLAGS)

projeto.o: projeto.c tabela.h
	gcc projeto.c -c $(FLAGS)

func1.o: func1.c tabela.h
	gcc func1.c -c $(FLAGS)

func2.o: func2.c tabela.h
	gcc func2.c -c $(FLAGS)

func3.o: func3.c tabela.h
	gcc func3.c -c $(FLAGS)

clean:
	rm -rf *.o projeto