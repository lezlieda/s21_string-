CC = gcc
EFLAGS = -Wall -Wextra -Werror -pedantic -std=c11 -g
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
	ranlib s21_string.a

test: s21_string.a
	$(CC) $(CFLAGS) main.c
	$(CC) $(OFLAGS) test s21_string.a main.o -lcheck
	./test

clean:
	rm -rf *.o *.a test

rebuild: clean all
