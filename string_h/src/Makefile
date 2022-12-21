CC = gcc
EFLAGS = -Wall -Wextra -Werror -std=c11 -g
CFLAGS = $(EFLAGS) -c
OFLAGS = $(EFLAGS) -o
S21_STRING_C = functions/*.c
S21_STRING_O = s21_*.o
S21_SUITE_C = tests/*.c
S21_SUITE_O = suite_*.o

all: test

s21_string.a:
	$(CC) $(CFLAGS) $(S21_STRING_C)
	ar r s21_string.a $(S21_STRING_O)
	rm -rf *.o
	ranlib s21_string.a

test: s21_string.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) $(OFLAGS) test $(S21_SUITE_O) main.o s21_string.a -lcheck
	rm -rf *.o *.a
	./test

gcov_report:
	$(CC) --coverage $(CFLAGS) $(S21_STRING_C)
	ar r s21_string.a $(S21_STRING_O)
	rm -rf *.o
	ranlib s21_string.a
	$(CC) $(CFLAGS) $(S21_SUITE_C) main.c
	$(CC) --coverage $(OFLAGS) test $(S21_SUITE_O) main.o s21_string.a -lcheck
	./test
	# gcov s21*.gcda
	# gcovr -r . --html --html-details -o report.html

clean:
	rm -rf *.o *.a test *.gcda *.gcno *.gcov *.html *.css

rebuild: clean all
