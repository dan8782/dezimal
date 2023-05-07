FLAGS_FOR_TEST = -lcheck -lm -lpthread 
FLAGS_STANDART =  -std=c11 -g -fsanitize=address
SRCS = $(shell find . -type f -name '*.c' -print)

all: test

test: ./tests/test_main.c
	gcc $(FLAGS_STANDART) $(FLAGS_FOR_TEST) $(SRCS) -o tests.exe
	./tests.exe
s21_decimal.a: $(OBJ)
	ar rcs s21_decimal.a $^
	rm *.o
gcov_report:
	gcc --coverage $(FLAGS_STANDART) $(FLAGS_FOR_TEST) $(SRCS) -o run_cov
	./run_cov
	lcov -c -d . -o s21_decimal.info --exclude "*test*"
	genhtml --footer "clockber, brillpau, burnerok" --dark-mode -o report s21_decimal.info
	open ./report/index.html
	make clean
	
clean:
	rm -rf tests.exe.dSYM
	rm -rf tests.exe
	rm -rf *.gcda *.gcno *.info *.a *.o
	rm -rf run_cov
	rm -rf run_cov.dSYM
	rm -rf run_test
	rm -rf report  

check_style:
	clang-format -style=Google -n *.c *.h