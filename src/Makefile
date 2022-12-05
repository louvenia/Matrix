UNAME := $(shell uname)

SOURCES=*.c
OBJECTS=*.o

DATE=date

CFLAGS = -Wall -Werror -Wextra -std=c11
CC = gcc
GFLAGS = -coverage
LDFLAGS = -lgcov
TFLAGS = -lcheck

all: clean s21_matrix.a test

s21_matrix.a:
	$(CC) $(CFLAGS) -c $(SOURCES)
	ar rc s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a
	rm -f *.o
	
ifeq ($(UNAME), Linux)
test: s21_matrix.a
	$(CC) $(CFLAGS) -c ./tests/matrix_test.c
	ar rc ./tests/matrix_test.a matrix_test.o
	ranlib ./tests/matrix_test.a
	$(CC) $(CFLAGS) --coverage -o c_tests s21_matrix.a ./tests/matrix_test.a $(SOURCES) -lcheck -lm -lsubunit -lrt -lpthread
	./c_tests
else
test: s21_matrix.a
	$(CC) $(CFLAGS) -c ./tests/matrix_test.c
	ar rc ./tests/matrix_test.a matrix_test.o
	ranlib ./tests/matrix_test.a
	$(CC) $(CFLAGS) --coverage -o c_tests s21_matrix.a ./tests/matrix_test.a $(SOURCES) -lcheck -lm -pthread
	./c_tests
endif

gcov_report: clean
	$(CC) $(SOURCES) $(ASAN) $(CFLAGS) $(LDFLAGS) $(GFLAGS) -c
	ar rcs s21_matrix.a $(OBJECTS)
	ranlib s21_matrix.a
	$(CC) $(ASAN) $(LDFLAGS) ./tests/matrix_test.c s21_matrix.a -o ./c_tests $(TFLAGS)
	./c_tests
	gcovr .
	gcovr --html-details -o report.html
	open ./report.html

clang-format: 
	clang-format -n *.c *.h

clang-correction: 
	clang-format -i *.c *.h

check:
	CK_FORK=no leaks --atExit -- ./c_tests

check_all: clang-format check

valgrind: s21_matrix.a
	touch valgrind.txt
	gcc -std=c11 ./tests/matrix_test.c s21_matrix.a -o check_unit_tests `pkg-config --cflags --libs check`
	valgrind --log-file="valgrind.txt" --trace-children=yes --track-fds=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ./c_tests

push: 
	git add .
	git commit -m "$(DATE)"
	git push origin develop

clean:	
	rm -rf s21_matrix.a ./tests/matrix_test.a *.gcda *.gcno *.css test *.dSYM *.html *.o ./html/*.html ./html/*.css ./c_tests valgrind.txt ./check_unit_tests
