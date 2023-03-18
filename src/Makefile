FLAGS_FOR_TEST = -lcheck -lm -lpthread 
FLAGS_STANDART =  -std=c11 -g #-fsanitize=address
SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)

all: test

test: ./tests/test_main.c
	gcc $(FLAGS_STANDART) $(FLAGS_FOR_TEST) $(SRCS) -o tests.exe
	./tests.exe
	
clean:
	rm -rf tests.exe.dSYM
	rm -rf tests.exe
