FLAGS_FOR_TEST = -lcheck -lm -lpthread 
FLAGS_STANDART = -Wall -Wextra -Werror -std=c11 -g -fsanitize=address

all: test

test: ./tests/test_main.c
	gcc $(FLAGS_STANDART) $(FLAGS_FOR_TEST) ./tests/*.c ./utils/*.c ./*.c ./comparison/*.c -o tests.exe
	./tests.exe
	
clean:
	rm -rf tests.exe.dSYM
	rm -rf tests.exe

check_style:
	clang-format -n ./lib/*.c ./tests/*.c
	clang-format -n *.h *.c ./tests/*.h%   