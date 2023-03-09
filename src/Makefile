FLAGS_FOR_TEST = -lcheck -lm -lpthread 
FLAGS_STANDART = -Wall -Wextra -Werror -std=c11 #-g #-fsanitize=address

all: test

test:
	gcc ./comparison/*.c ./utils/*.c *.c -o run_test
	./run_test

clean:
	rm -rf *.gcda *.gcno *.info *.a
	rm -rf run_cov
	rm -rf run_test
	rm -rf report  

check_style:
	clang-format -n ./lib/*.c ./tests/*.c
	clang-format -n *.h *.c ./tests/*.h%   