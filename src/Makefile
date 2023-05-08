FLAGS_FOR_TEST = $(shell pkg-config --libs --cflags check)
FLAGS_STANDART =  -Wall -Wextra -Werror -std=c11 -g -fsanitize=address
SRCS = $(shell find . -type f -name '*.c' -print)
SRCS_LIB = $(shell find . -path ./tests -prune -o -name '*.c' -print)
SRCS_LCOV = $(shell find . -type f -name 's21_*.gcda' -print)

all: s21_decimal.a test

s21_decimal.a: $(SRCS_LIB)
	gcc $(FLAGS_STANDART) -c $(SRCS_LIB)
	ar r s21_decimal.a *.o
	rm -rf *.o

test: ./tests/*.c
	gcc $(FLAGS_STANDART) $(FLAGS_FOR_TEST) $(SRCS) -o tests_run
	./tests_run

gcov_report: test s21_decimal.a
	gcc --coverage $(FLAGS_STANDART) $(FLAGS_FOR_TEST) $(SRCS) -o run_cov
	./run_cov
	lcov -c -d . -o s21_decimal.info --exclude '*test_*'  --exclude '*/utils/*'
	genhtml --footer "clockber, brillpau, burnerok" --dark-mode -o report s21_decimal.info
	open ./report/index.html
	
clean:
	rm -rf tests_run.dSYM
	rm -rf tests_run
	rm -rf *.gcda *.gcno *.info *.a *.o
	rm -rf run_cov
	rm -rf run_cov.dSYM
	rm -rf run_test
	rm -rf report  

check_style:
	clang-format -style=Google -n *.c *.h