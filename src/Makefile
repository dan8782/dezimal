FLAGS_FOR_TEST = -lcheck -lm -lpthread 
FLAGS_STANDART =  -std=c11 -g #-fsanitize=address

all: test

test: ./tests/test_main.c
	gcc $(FLAGS_STANDART) $(FLAGS_FOR_TEST)  ./tests/*.c ./converters/*.c ./utils/*.c ./*.c ./comparison/*.c -o tests.exe
	./tests.exe
	
clean:
	rm -rf tests.exe.dSYM
	rm -rf tests.exe
